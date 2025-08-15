#include <iostream>
#include <set>
#include <climits>

using namespace std;



void solve(){
    int n, m;
    int arr[101][101];

    cin >> n >> m;
    int w, a, b;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = 0x3f3f3f3f;
        }
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b >> w;
        arr[a][b] = min(arr[a][b], w);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i]+arr[i][k]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(arr[i][j] == 0x3f3f3f3f) arr[i][j] = 0;
            cout << arr[i][j] << " ";
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
