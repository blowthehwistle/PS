#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;

vector<vector<int>> comb;

void BinaryPerm(int n, vector<int>& result, int depth=0) {
    if(depth == n) {
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(result[i] == 1) {
                flag = true;
                break;
            }
        }
        if(!flag) return;
        comb.push_back(result);
        return;
    }
    for(int i=0; i<=1; i++) {
        result[depth] = i;
        BinaryPerm(n, result, depth+1);
    }
}

void solve() {
    int n;
    bool success = true;
    stack<int> s;

    vector<pii> v;
    cin >> S;
    for(int i=0; i<S.size(); i++) {
        if(S[i] == '(') {
            s.push(i);
        }
        if(S[i] == ')') {
            int x = s.top();
            s.pop();
            v.push_back(make_pair(x, i));
        }
    }
    n = v.size();   //괄호의 갯수
    vector<int> result(n);
    BinaryPerm(n, result);

    set<string> answer;
    for(int i=0; i<comb.size(); i++) {
        vector<bool> rem(S.size()); //
        for(int j=0; j<n; j++) {
            if(comb[i][j] != 0) {
                rem[v[j].first] = true;
                rem[v[j].second] = true;
            }
        }
        string temp_s = "";
        for(int j=0; j<S.size(); j++) {
            if(rem[j]) continue;
            temp_s += S[j];
        }
        answer.insert(temp_s);
    }

    // sort(answer.begin(), answer.end());
    for(auto iter:answer) {
        cout << iter << "\n";
    }
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