#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include<algorithm>

#define MAX_N 1000001
using namespace std;

int n, m;
int p[MAX_N];

void solve() {
    int n;
    vector<int> v;
    cin >> n;
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    int _max = v[0], _min = v[0];
    for(int i=1; i<v.size(); i++) {
        if(_max < v[i]) {
            _max = v[i];
        }
        if(_min > v[i]) {
            _min = v[i];
        }
    }
    cout << _min << " " << _max << "\n";
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    while(tc--) solve();


    return 0;
}
