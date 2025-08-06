
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <cmath>
using namespace std;

int k;
int n;
void solve(){
    cin >> n;
    vector<int> parent(n);
    vector<bool> invalid(n);
    vector<vector<int>> v(n);
    queue<int> q;

    for(int i=0; i<n; i++) {
        cin >> parent[i];
        if(parent[i] == -1) continue;
        v[parent[i]].push_back(i);
    }

    cin >> k;



    q.push(k);
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        invalid[x] = true;
        for(int i=0; i<v[x].size(); i++) {
            if(invalid[v[x][i]]) continue;
            invalid[v[x][i]] = true;
            q.push(v[x][i]);
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(!invalid[i]) {
            if( v[i].size() == 0) {
                cnt++;
            }
            else {
                bool leaf = true;
                for(int j=0; j<v[i].size(); j++) {
                    if(!invalid[v[i][j]]) {
                        leaf = false;
                        break;
                    }
                }
                if(leaf) {
                    cnt++;
                }
            }

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