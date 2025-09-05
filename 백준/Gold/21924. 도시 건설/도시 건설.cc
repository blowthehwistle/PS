#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include<algorithm>

#define MAX_N 100001
using namespace std;

int n, m;
int p[MAX_N];

int find(int x) {
    if(p[x]<0) return x;
    return p[x] = find(p[x]);

}

bool uni(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) {
        return false;
    }
    if(p[v] < p[u]) {   //v가 더 깊음
        swap(u, v); //u가 더 깊어짐
    }
    if(p[u] == p[v]) {
        p[u]--;
    }
    p[v] = u;

    return true;
}

void solve() {
    //tree
    int a, b, w;
    vector<tuple<int, int, int>> v;
    fill(p, p+MAX_N, -1);

    cin >> n >> m;
    long long total = 0;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> w;
        v.push_back({w, a, b});
        total += w;
    }
    long long answer = 0;
    int cnt=0;
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        tie(w, a, b) = v[i];
        if(uni(a, b)) {
            answer += w;
            cnt++;
            if(cnt == n-1) {
                break;
            }
        }
    }
    if(cnt == n-1) {
        cout << total-answer;
    }
    else {
        cout << -1;
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
