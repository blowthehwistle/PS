#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

bool arr[100][100];
int n, m, k;

vector<pair<int, int>> adj[10001];
bool mst[10001];
priority_queue<tuple<int, int, int>> pq;

void solve() {
    int v, e;
    cin >> v >> e;

    fill(mst, mst+10001, false);
    int a, b, c;
    for(int i=0; i<e; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    mst[1] = true;
    for(auto nxt:adj[1]) {
        pq.push({-nxt.first, 1, nxt.second});
    }

    int cnt = 0;
    long long answer = 0;
    while(cnt < v-1) {
        int cost, s, t;
        tie(cost, s, t) = pq.top(); pq.pop();
        cost = -cost;
        if(mst[t]) continue;
        cnt++;
        mst[t] = true;
        answer += cost;
        for(auto nxt:adj[t]) {
            if(!mst[nxt.second]) pq.push({-nxt.first, t, nxt.second});
        }

    }
    cout << answer;
}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
