#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int find(vector<int>& parent, int x){
    if(parent[x] != x){
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void UnionSet(vector<int>& parent, int a, int b){
    a = find(parent, a);
    b = find(parent, b);
    if(a != b){
        parent[b] = a;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> root(n);
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<n; i++){
        root[i] = i;
    }
    int cnt = 0;
    for(int i=0; i<costs.size(); i++){
        if(cnt == n-1) break;

        int s = costs[i][0];
        int t = costs[i][1];
        int cst = costs[i][2];
        
        if(find(root, s) != find(root, t)){
            answer += cst;
            UnionSet(root, s, t);
            cnt++;
        }       
    }
    
    return answer;
}