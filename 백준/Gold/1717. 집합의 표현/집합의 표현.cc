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



int find(int a) {
    if(parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[a] = b;
    return true;
}

bool chk(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return true;

    return false;
}


void solve() {
    fill(parent, parent+MAX_N+1, -1);
    cin >> n >> m;
    int a, b, cmd;
    for(int i=0; i<m; i++) {
        cin >> cmd >> a >> b;
        if(cmd == 0) {
            uni(a, b);
        }
        else if(cmd == 1) {
            bool result = chk(a, b);
            if(result) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
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
