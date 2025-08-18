#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;


const int MAX_N = 100000;
const int INF = 0x3f3f3f3f;
void solve(){
    int n;
    long long answer = 0;
    cin >> n;

    for(int i=0; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            answer += (i + j);
        }
    }
    cout << answer << "\n";


}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
