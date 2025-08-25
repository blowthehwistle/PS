#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

#define MAX_N 1000000
using namespace std;


int n, m;
int boss[100001];
vector<int> graph[100001];

// void traverse(int x, vector<int>& comp, int w) {
//     comp[x] += w;
//     for(int i=0; i<graph[x].size(); i++) {
//         int nxt = graph[x][i];
//         traverse(nxt, comp, w);
//     }
// }

void solve() {
    //tree

    cin >> n >> m;
    vector<int> comp(n+1);
    vector<int> dp(n+1);

    for(int i=1; i<=n; i++) {
        cin >> boss[i];
        if(boss[i] == -1) continue;
        // graph[i].push_back(boss[i]);
        graph[boss[i]].push_back(i);
    }
    int node, w;
    for(int i=0; i<m; i++) {
        cin >> node >> w;
        comp[node] += w;
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int x = q.front(); q.pop();

        if(x == 1) {
            dp[x] = comp[x];
        }else {
            dp[x] = dp[boss[x]] + comp[x];
        }

        for(int i=0; i<graph[x].size(); i++) {
            q.push(graph[x][i]);
        }
    }
    for(int i=1; i<=n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
