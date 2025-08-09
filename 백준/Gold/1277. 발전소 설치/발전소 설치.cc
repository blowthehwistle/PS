#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, w; double m;
    priority_queue<pair<double,int>> pq; // max-heap이므로 음수로 넣는 방식 그대로 사용

    cin >> n >> w >> m;

    vector<pair<int,int>> v_idx(n+1);
    vector<vector<bool>> made(n+1, vector<bool>(n+1, false));
    vector<double> dists(n+1, 1e100);
    vector<bool> visited(n+1, false);

    for(int i=1;i<=n;i++){
        int a,b; cin >> a >> b;
        v_idx[i] = {a,b};
    }
    for(int i=0;i<w;i++){
        int a,b; cin >> a >> b;
        made[a][b] = made[b][a] = true;
    }

    dists[1] = 0.0;
    pq.push({0.0, 1}); // 음수 안 쓰려면 greater로 바꾸는 게 깔끔하지만, 일단 유지

    while(!pq.empty()){
        int x = pq.top().second;
        double cur_dist = -1.0 * pq.top().first; // 음수로 넣을 거면 여기서 -1 곱해야함
        pq.pop();

        // max-heap + 음수 전략이면 push할 때 -dist로 넣어야 함
        // 지금은 0.0을 그대로 넣었으니, 아래 라인처럼 일관성 맞추자:
        if (cur_dist != dists[x]) continue; // outdated 제거
        if (visited[x]) continue;
        visited[x] = true;

        for(int i=1; i<=n; i++){            // ✅ 범위 1..n
            if (i == x) continue;

            double dist_vertex;
            if (made[x][i]){
                dist_vertex = 0.0;
            } else {
                int dx = abs(v_idx[x].first  - v_idx[i].first);
                int dy = abs(v_idx[x].second - v_idx[i].second);
                if (dx > m || dy > m) continue;           
                double d = hypot((double)dx, (double)dy); 
                if (d > m) continue;                      
                dist_vertex = d;
            }

            double nd = cur_dist + dist_vertex;
            if (!visited[i] && nd < dists[i]) {           
                dists[i] = nd;
                pq.push({-nd, i});                        
            }
        }
    }

    cout << (int)(dists[n] * 1000);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}