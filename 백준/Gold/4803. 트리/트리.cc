#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'

using namespace std;

const int MAX = 500 + 3;
int N, M;
bool visited[MAX];
vector<int> adj[MAX];

bool isCyclic(int node, int parent) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            if (isCyclic(next, node)) return true;
        } else if (next != parent) {
            return true; // cycle found
        }
    }
    return false; // no cycle
}

void solve(int caseNum) {
    cin >> N >> M;
    if (N == 0 && M == 0) exit(0);

    for (int i = 1; i <= N; ++i) adj[i].clear();
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int treeCount = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            if (!isCyclic(i, -1)) {
                ++treeCount;
            }
        }
    }

    cout << "Case " << caseNum;
    if (treeCount == 0) {
        cout << ": No trees." << endl;
    } else if (treeCount == 1) {
        cout << ": There is one tree." << endl;
    } else {
        cout << ": A forest of " << treeCount << " trees." << endl;
    }
}

int main() {
    fastio;
    for (int caseNum = 1;; ++caseNum) {
        solve(caseNum);
    }
    return 0;
}