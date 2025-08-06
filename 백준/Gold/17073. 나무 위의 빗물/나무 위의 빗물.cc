#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <cmath>
using namespace std;

int k;
int n;
void solve(){
    int w;
    cin >> n >> w;
    vector<vector<int>> v(n+1);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for(int i=2; i<=n; i++) {
        if(v[i].size() == 1) {
            cnt++;
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << (double)w/(double)cnt;
}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}