#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;

void solve() {
    int n;
    bool success = true;
    stack<pii> s;

    vector<pii> v;
    cin >> n;
    int x, r;
    for(int i=0; i<n; i++) {
        cin >> x >> r;
        v.push_back(make_pair(x-r, x+r));
    }

    sort(v.begin(), v.end());

    int ptr = v[0].first;

    for(int i=0; i<n; i++) {
        int st = v[i].first;
        int en = v[i].second;

        if(!s.empty()) {
            while(!s.empty() && st > s.top().second) {
                s.pop();
            }
            if(!s.empty() && en >= s.top().second) {
                success = false;
                break;
            }
        }
        s.push(v[i]);

    }
    if(success) {
        cout << "YES";
    }else {
        cout << "NO";
    }
    cout << "\n";
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    //cin >> t;
    while (tc--) solve();
    return 0;
}