#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    
    for(const auto& iter: puddles){
        dp[iter[1]][iter[0]] = -1;    
    }
    
    dp[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j] == -1) continue;
            if(i == 1 && j == 1)continue;
            if(dp[i-1][j] > 0 && dp[i][j-1] > 0){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= 1000000007;                
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            // cout << dp[i][j] << " ";
            
        }
        // cout << "\n";
    }
    answer = dp[n][m];
    
    return answer;
}