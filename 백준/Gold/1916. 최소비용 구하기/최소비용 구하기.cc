#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool arr[100][100];
int n, m, k;

vector<vector<pair<int, int>>> v(1001);
priority_queue<pair<int, int>> pq;
int costs[1001];
void solve(){
    fill(costs, costs+1001, 100000000);

    cin >> n >> m;
    int s, t, c;
    for(int i=0; i<m; i++) {
        cin >> s >> t >> c;
        v[s].push_back(make_pair(c, t));
    }
    cin >> s >> t;
    pq.push(make_pair(0, s));
    costs[s] = 0;
    while(!pq.empty()) {
        int cst = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(costs[x] != cst) continue;
        for(int i=0; i<v[x].size(); i++) {
            int nxt = v[x][i].second;
            int nxt_cst = v[x][i].first;
            if(costs[nxt] > cst+nxt_cst) {
                costs[nxt] = cst+nxt_cst;
                pq.push(make_pair(-costs[nxt], nxt));
            }
        }
    }
    cout << costs[t];
}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
