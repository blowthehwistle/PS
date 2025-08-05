
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <cmath>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n+1);
    vector<pair<int, int>> edge;
    int a, b;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b;
        edge.push_back(make_pair(a, b));
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    int t, k;
    cin >> q;
    for(int i=0; i<q; i++) {
        cin >> t >> k;
        if(t == 1) {
            if(v[k].size() == 1) {
                cout << "no\n";
            }else {
                cout << "yes\n";
            }
        }
        if(t == 2) {
            cout << "yes\n";
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