/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
#include <queue>

using namespace std;


int n, m;
vector<vector<int>> comb;
void dfs(int depth, int cur, vector<int> v, vector<bool> visited){
    if(cur == depth){
        comb.push_back(v);
        return;
    }
    for(int i=0; i<m; i++){
        if(!visited[i]){
            v.push_back(i);
            visited[i] = true;
            dfs(depth, cur+1, v, visited);
            visited[i] = false;
            v.pop_back();
        }
    }
    
}

void solve(){
    cin >> n >> m;
    
    vector<vector<int>> v(n);
    vector<int> sat(n);
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            v[i].push_back(temp);
            sat[i] += temp;
        }
    }
    vector<int> vec;
    vector<bool> visited(m);

    dfs(3, 0, vec, visited);
    // for(int i=0; i<comb.size(); i++){
    //     for(int j=0; j<comb[i].size(); j++){
    //         cout << comb[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "comb size : " << comb.size() << "\n";
    int max_sat = 0;
    for(int i=0; i<comb.size(); i++){
        int temp_sat = 0;
        for(int j=0; j<n; j++){
            int person_sat = 0;
            for(int k=0; k<comb[i].size(); k++){
                int idx = comb[i][k];
                person_sat = max(v[j][idx], person_sat);
            }
            temp_sat += person_sat;
        }
        max_sat = max(max_sat, temp_sat);
    }    
    cout << max_sat;
}
int main()
{
    cin.tie(0);
    
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    
    
    return 0;
}