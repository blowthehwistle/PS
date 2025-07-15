#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> v(n+1, vector<bool>(n+1));
    
    
    for(int i=0; i<results.size(); i++){
        v[results[i][0]][results[i][1]] = true;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(v[j][i] == true && v[i][k] == true){
                    v[j][k] = true;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(v[i][j] == true || v[j][i]==true) cnt++;
        }
        if(cnt == n-1) answer++;         
    }
            
    
    
    return answer;
}