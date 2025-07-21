#include <string>
#include <queue>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;
queue<int> c, p;


void solve() {
    int a, b;
    cin >> a >> b;
    cout <<  a + b << "\n";
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    for(int i=1; i<=tc; i++) {
        cout <<"Case #" << i << ": ";
        solve();
    }
    return 0;
}