#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    int cnt = times.size(), cur_t = 0;
    
    long long end_time = (long long)*max_element(times.begin(), times.end()) * n;
    long long lptr = 1, rptr = end_time;
    
    long long mid;
    while(lptr <= rptr){
        mid = (lptr+rptr) / 2;
        long long ppl1 = 0;
        for(int i=0; i<times.size(); i++){
            ppl1 += mid/times[i];
        }
        if(ppl1 < n){
            lptr = mid + 1;
        }else{
            answer = mid;
            rptr = mid - 1;
        }
    }
    
    return answer;
}