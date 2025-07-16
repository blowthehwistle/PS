#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    
    sort(people.begin(), people.end(), greater<>());
    int lptr = 0, rptr = people.size()-1;
    
    while(lptr <= rptr){
        int x = people[lptr];
        lptr++;
        if(x + people[rptr] <= limit){
            rptr--;
        }
        answer++;
    }
    
    
    return answer;
}