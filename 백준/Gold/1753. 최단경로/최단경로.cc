#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;



void solve(){
    int v, e;
    int k;
    priority_queue<pair<int,int>> pq;

    cin >> v >> e;
    cin >> k;
    vector<vector<pair<int, int>>> g(v+1);
    vector<int> dist(v+1);

    for(int i=0; i<v+1; i++) {
        dist[i] = INT_MAX;
    }
    int w, a, b;
    for(int i=0; i<e; i++) {
        cin >> a >> b >> w;
        g[a].push_back(make_pair(b, w));
    }

    pq.push(make_pair(0,k));
    dist[k] = 0;
    while(!pq.empty()){
        int x =  pq.top().second;
        int cur_dist = -1 * pq.top().first;
        pq.pop();

        if(cur_dist != dist[x]) continue;
        for(int i=0; i<g[x].size(); i++){
            int next = g[x][i].first;
            int weight = g[x][i].second;
            if(dist[next] > dist[x]+weight) {
                pq.push(make_pair(-1.0 * (dist[x]+weight), next));
                dist[next] = dist[x]+weight;
            }
        }
    }

    for(int i=1; i<=v; i++) {
        if(dist[i] == INT_MAX) {
            cout << "INF\n";
        }else {
            cout << dist[i] << "\n";
        }
    }


}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
