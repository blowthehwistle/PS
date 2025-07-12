#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    queue<pair<int, int>> q;
    vector<vector<int>> v(n+1);
    vector<bool> visited(n+1);
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++){
        int s = edge[i][0];
        int d = edge[i][1];
        
        v[s].push_back(d);
        v[d].push_back(s);
    }
    
    q.push(make_pair(1, 0));
    
    int max_dist = 0;
    while(!q.empty()){
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();

        if(visited[x]) continue;

        if(dist == max_dist){
            answer++;    
        }else if(dist > max_dist){
            answer = 1;
            max_dist = dist;
        }
        
        visited[x] = true;        
        
        for(int i=0; i<v[x].size(); i++){
            int target = v[x][i];
            if(!visited[target]){
                q.push(make_pair(target, dist+1));
            }   
        }        
    }
    
    return answer;
}