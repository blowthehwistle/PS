#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    int s1, s2;
    for(int i=1; i<size; i++){
        for(int j=0; j<triangle[i].size(); j++){
            if(j == triangle[i].size()-1) 
                s1 = 0;
            else
                s1 = triangle[i][j] + dp[i-1][j];
            if(j-1 < 0)
                s2 = 0;
            else
                s2 =  triangle[i][j] + dp[i-1][j-1];
            
            dp[i].push_back(max(s1, s2));
        }                
    }
    for(int i=0; i<dp[size-1].size(); i++){
        answer = max(answer, dp[size-1][i]);
    }
    return answer;
}