#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int camidx = routes[0][1];
    answer = 1;
    for(int i=0; i<routes.size(); i++){
        if(camidx < routes[i][0]){
            camidx = routes[i][1];
            answer++;
        }
    }
        
    
    
    return answer;
}

