#include <iostream>
#include <set>
#include <climits>
#include <vector>
using namespace std;



void solve(){
    int n, m;
    int arr[101][101];
    int nxt[101][101];
    const int INF = 0x3f3f3f3f;
    cin >> n >> m;
    int w, a, b;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
            nxt[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b >> w;
        arr[a][b] = min(arr[a][b], w);
        nxt[a][b] = b;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                if(arr[j][k] > arr[j][i]+arr[i][k]) {
                    arr[j][k] = arr[j][i]+arr[i][k];
                    nxt[j][k] = nxt[j][i];  //왜?
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(arr[i][j] == INF) cout << 0 << " ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    vector<vector<int>> route(n*n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int s = i+1;
            int t = j+1;
            int k = nxt[s][t];
            if(s == t) continue;
            if(arr[s][t] == INF) continue;
            route[i*n+j].push_back(s);
            while(k != t) {
                route[i*n+j].push_back(k);
                k = nxt[k][t];
            }
            route[i*n+j].push_back(t);
        }
    }

    for(int i=0; i<n*n; i++) {
        cout << route[i].size() << " ";
        for(int j=0; j<route[i].size(); j++) {
            cout << route[i][j] << " ";
        }
        cout << "\n";
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
