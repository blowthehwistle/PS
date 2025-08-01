#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;

void solve() {
    map<string, int> m;
    string s;
    int n;
    long long x;
    multiset<pair<long long, bool>> mst;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        if(x == 0) {
            if(!mst.empty()) {
                if(!mst.begin()->second) {
                    cout << mst.begin()->first * -1 << "\n";
                }else {
                    cout << mst.begin()->first << "\n";

                }
                mst.erase(mst.begin());
            }
            else {
                cout << 0 << "\n";
            }
        }else {
            if(x < 0) {
                x = -x;
                mst.insert(make_pair(x, false));
            }else {
                mst.insert(make_pair(x, true));
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}