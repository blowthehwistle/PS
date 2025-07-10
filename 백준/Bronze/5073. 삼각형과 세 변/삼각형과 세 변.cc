#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;
queue<int> c, p;


void solve() {
    vector<int> v(3);
    int n1, n2, n3;
    while(1) {
        cin >> v[0] >> v[1] >> v[2];
        if(v[0] == 0 && v[1] == 0 && v[2] == 0)
            return;
        sort(v.begin(), v.end(), greater<>());
        if(v[0] >= v[1]+v[2]) {
            cout << "Invalid\n";
        }
        else if(v[0] == v[1] && v[1] == v[2]) {
            cout << "Equilateral\n";
        }
        else if(v[0] == v[1] || v[1] == v[2]) {
            cout << "Isosceles\n";
        }
        else {
            cout << "Scalene\n";
        }
    }
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