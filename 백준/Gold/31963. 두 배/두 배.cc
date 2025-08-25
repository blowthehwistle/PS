#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

#define MAX_N 250000
using namespace std;

int n, m;

void solve() {
    cin >> n;
    int arr[MAX_N];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int cnt=0;
    for(int i=1; i<n; i++) {
        while(arr[i] < arr[i-1]) {
            cnt++;
            arr[i] *= 2;
        }
    }
    cout << cnt;

}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
