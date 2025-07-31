#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;

vector<vector<int>> comb;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) {
        return a.second>b.second;
    }
    return a < b;
}

void solve() {
    int n;
    int p, l;
    cin >> n;
    multiset<int, greater<>> mst;
    char op;
    int k;
    for(int i=0; i<n; i++) {
        cin >> op >> k;
        if(op == 'I') {
            mst.insert(k);
        }
        if(op == 'D') {
            if(k == 1) {
                if(!mst.empty()) {
                    mst.erase(mst.begin());
                }
            }
            else if(k == -1) {
                if(!mst.empty()) {
                    mst.erase(prev(mst.end()));
                }
            }
        }
    }

    if(mst.empty()) {
        cout << "EMPTY" << "\n";
    }
    else {
        cout << *mst.begin() << " ";
        if(mst.size() == 1) {
            cout << *mst.begin() << "\n";
        }else {
            cout << *prev(mst.end()) << "\n";
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}