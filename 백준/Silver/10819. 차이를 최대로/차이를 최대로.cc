#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> perm;
vector<int> v;

void dfs(int depth, int cur_d, vector<bool> visited, vector<int> ans) {
    if(depth == cur_d) {
        perm.push_back(ans);
        return;
    }
    for(int i=0; i<v.size(); i++) {
        if(!visited[i]) {
            ans.push_back(v[i]);
            visited[i] = true;
            dfs(depth, cur_d+1, visited, ans);
            visited[i] = false;
            ans.pop_back();
        }
    }
}

void solve(){
    int n, l;
    cin >> n;
    priority_queue<int> pq;

    vector<bool> visit(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    vector<int> vv;
    dfs(n, 0, visit, vv);
    int max_sum = 0;
    int sum = 0;
    for(int i=0; i<perm.size(); i++) {
        sum = 0;
        for(int j=0; j<perm[i].size()-1; j++) {
            int cur = perm[i][j];
            int next = perm[i][j+1];
            sum += abs(cur - next);
        }
        max_sum = max(max_sum, sum);
    }
    cout << max_sum;
}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
