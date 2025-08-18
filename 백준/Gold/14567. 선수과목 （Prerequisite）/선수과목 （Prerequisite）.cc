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
    int n, m;
    queue<int> q;
    cin >> n >> m;

    vector<int> indegree(n+1);
    vector<vector<int>> ingraph(n+1);
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        indegree[b]++;
        ingraph[b].push_back(a);
        graph[a].push_back(b);
    }
    vector<int> sem(n+1);
    for(int i=1; i<=n; i++) {
        sem[i] = 1;
        if(indegree[i] == 0) {
            q.push(i);
            // visited[i] = true;
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        int max_sem = 0;
        bool success = true;
        for(int i=0; i<ingraph[x].size(); i++) {
            int next = ingraph[x][i];
            max_sem = max(max_sem, sem[next]);
            if(!visited[next]) {
                success = false;
                break;
            }
        }
        if(!success) {
            q.push(x);
            continue;
        }
        visited[x] = true;
        sem[x] = max_sem + 1;
        for(int i=0; i<graph[x].size(); i++) {
            int next = graph[x][i];
            indegree[next]--;
            if(indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << sem[i] << " ";
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
