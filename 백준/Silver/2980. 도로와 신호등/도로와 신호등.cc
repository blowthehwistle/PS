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
    int n, l;
    int answer = 0;
    cin >> n >> l;

    int d, r, g;
    int v[1001][3];
    for(int i=0; i<n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    int curPos = 0, curTime = 0;
    for(int i=0; i<n; i++) {
        int r = v[i][1];
        int g = v[i][2];
        curTime += v[i][0]-curPos;
        curPos = v[i][0];
        // cout << "curTime : " << curTime << "\n";
        int restTime = curTime % (r + g);
        // cout << "restTime : " << restTime << "\n";
        if(restTime > 0) {
            if(restTime - r < 0) {
            // cout << "additional Time : " << r-restTime << "\n";
                curTime += (r-restTime);
            }
        }else {
            curTime += r;
        }
    }
    curTime += l-v[n-1][0];

    cout << curTime << "\n";


}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
