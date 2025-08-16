#include <iostream>
#include <set>
#include <climits>
#include <vector>
#include <queue>
using namespace std;


const int MAX_N = 100000;
const int INF = 0x3f3f3f3f;
void solve(){
    int n, k;
    priority_queue<pair<int, int>> pq;
    cin >> n >> k;

    int costs[2*MAX_N + 1];
    fill(costs, costs + 2*MAX_N + 1, -1);

    pq.push(make_pair(0, n));
    costs[n] = 0;
    while(!pq.empty()) {
        int cst = -1 * pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (costs[v] != cst) continue;
        if(v == k) {
            cout << cst << "\n";
            break;
        }

        int nxt = v-1;
        if (0 <= nxt && nxt <= 2*MAX_N) {
            if (costs[nxt] == -1 || costs[nxt] > cst + 1) {
                costs[nxt] = cst + 1;
                pq.push({-(cst + 1), nxt});
            }
        }
            nxt = v+1;
            if (0 <= nxt && nxt <= 2*MAX_N) {
                if (costs[nxt] == -1 || costs[nxt] > cst + 1) {
                    costs[nxt] = cst + 1;
                    pq.push({-(cst + 1), nxt});
                }
            }
            nxt = v*2;
            if (0 <= nxt && nxt <= 2*MAX_N) {
                if (costs[nxt] == -1 || costs[nxt] > cst) {
                    costs[nxt] = cst;
                    pq.push({-cst, nxt});
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
