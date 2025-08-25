#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

#define MAX_N 1000000
using namespace std;

int parent[MAX_N+1];
int n, m, k;
int start, endd;
int cur;
deque<int> idx;


void solve() {
    cin >> n;
    vector<bool> exist(n);
    vector<int> cmd(n);

    for(int i=0; i<n; i++) {
        cin >> cmd[i];
        idx.push_back(i);
    }

    deque<int> answer;
    start = 0;
    endd = n-1;
    for(int i=0; i<n; i++) {
        if(cmd[i] == 1) {
            answer.push_front(idx.front());
            idx.pop_front();
        }
        if(cmd[i] == 2) {
            answer.push_front(*(idx.begin()+1));
            idx.erase(idx.begin()+1);
        }
        if(cmd[i] == 3) {
            answer.push_front(idx.back());
            idx.pop_back();
        }
    }
    vector<int> real_ans(n);
    for(int i=0; i<n; i++) {
        real_ans[answer[i]] = i;
    }
    for(int i=0; i<n; i++) {
        cout << real_ans[i]+1 << " ";
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
