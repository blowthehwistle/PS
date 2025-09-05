#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include<algorithm>

#define MAX_N 100001
using namespace std;

int n, m;
int p[MAX_N];

void solve() {
    bool subm[31];
    fill(subm, subm+31, false);
    int n;
    for(int i=0; i<28; i++) {
        cin >> n;
        subm[n] = true;
    }
    for(int i=1; i<=30; i++) {
        if(!subm[i]) cout << i << "\n";
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
