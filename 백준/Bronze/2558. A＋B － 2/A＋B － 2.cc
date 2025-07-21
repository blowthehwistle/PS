#include <string>
#include <queue>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;
queue<int> c, p;


void solve() {
    int a, b;
    cin >> a >> b;
    cout << a+b;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);  // input.txt로부터 입력 받기

    int tc = 1;
    //cin >> t;
    while (tc--) solve();
    return 0;
}