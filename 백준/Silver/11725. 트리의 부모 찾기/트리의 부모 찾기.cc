/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <cmath>
using namespace std;



void solve(){
    int n;
    cin >> n;

    queue<int> q;
    vector<int> p(n+1);
    vector<vector<int>> v(n+1);

    int a, b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    p[1] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++) {
            int tgt = v[x][i];
            if(p[tgt] == 0) {
                p[tgt] = x;
                q.push(tgt);
            }
        }
    }
    for(int i=2; i<=n; i++) {
        cout << p[i] << "\n";
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