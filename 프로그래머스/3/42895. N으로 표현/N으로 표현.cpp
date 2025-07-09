#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<set<int>> dp(9);
    queue<int> q;    
    
    if(N == number) return 1;
    dp[1].insert(N);
    for(int i=2; i<9; i++){
        string s = "";
        for(int j=0; j<i; j++){
            s += to_string(N);
        }
        dp[i].insert(stoi(s));
        
        for(int j=1; j < i ; j++){
            if(i-j>0){
                for(auto it1: dp[j]){
                    for(auto it2: dp[i-j]){

                        dp[i].insert(it1 + it2);
                        dp[i].insert(it1 - it2);
                        dp[i].insert(it1 * it2);
                        if(it2 != 0) dp[i].insert(it1 / it2);
                        if (dp[i].count(number)) return i;
                    }
                }
            }
        }
    }
            
    
    
    return answer;
}