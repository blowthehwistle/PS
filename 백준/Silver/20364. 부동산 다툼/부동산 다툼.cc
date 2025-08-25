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


int n, q;

void solve() {
    cin >> n >> q;
    vector<int> want_node(q);
    vector<bool> occupied(n+1);
    fill(occupied.begin(), occupied.end(), false);
    for(int i=0; i<q; i++) {
        cin >> want_node[i];
    }
    for(int i=0; i<q; i++) {
        int temp = want_node[i];
        bool success = true;
        int occpd_g;
        while(temp != 1) {
            if(occupied[temp]) {
                success = false;
                occpd_g = temp;
            }
            temp /= 2;
        }
        if(!success) {
            cout << occpd_g << "\n";
        }
        else {
            cout << "0\n";
            occupied[want_node[i]] = true;
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
