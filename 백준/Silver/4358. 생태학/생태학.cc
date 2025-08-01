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
    int cnt=0;
    while(getline(cin, s)) {
        m[s]++;
        cnt++;
    }

    for(auto iter: m) {
        cout << iter.first << " " <<fixed << setprecision(4) << (double)iter.second / cnt * 100 << "\n";
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