#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

#define MAX_N 1000000
using namespace std;

int parent[MAX_N+1];
int n, m, k;



void solve() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=1; j<m; j++) {
            cout << i*m+j << " ";
        }
        cout << i*m+m << "\n";

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
