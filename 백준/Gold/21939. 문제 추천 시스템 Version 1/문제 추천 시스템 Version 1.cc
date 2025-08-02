#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;

vector<vector<int>> comb;


struct cmp {
    bool operator() (const pii& a, const pii& b) const {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
void solve() {
    int n, m;
    int p, l;
    cin >> n;
    set<pii, cmp> s;
    map<int, int> pnum;
    string op;
    for(int i=0; i<n; i++) {
        cin >> p >> l;
        s.insert(make_pair(l, p));
        pnum[p] = l;
    }

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> op;
        if (op == "recommend") {
            int x;
            cin >> x;
            if (x == 1 && !s.empty()) {
                cout << s.begin()->second << "\n";

            } else if (x == -1 && !s.empty()) {
                pair<int, int> p = *(prev(s.end()));
                cout << s.rbegin()->second << "\n";
            }
        }
        else if(op == "add") {
            cin >> p >> l;
            s.insert(make_pair(l, p));
        }
        else if(op == "solved") {
            cin >> p;
            int lv = pnum[p];
            if(!s.empty()) {
                s.erase(make_pair(lv, p));
            }
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
    return 0;
}