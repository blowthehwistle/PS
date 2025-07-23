#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;

void solve() {
    int n;
    stack<pii> s;
    cin >> n;
    vector<int> answer;
    int temp;
    for(int i=1; i<=n; i++) {
        cin >> temp;
        while(!s.empty() && s.top().first < temp) {
            s.pop();
        }
        if(!s.empty()) {
            answer.push_back(s.top().second);
        }else {
            answer.push_back(0);
        }
        s.push(make_pair(temp, i));
    }
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    //cin >> t;
    while (tc--) solve();
    return 0;
}