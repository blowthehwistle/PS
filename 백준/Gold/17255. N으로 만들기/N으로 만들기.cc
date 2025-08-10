#include <bits/stdc++.h>
using namespace std;

string s;

set<set<string>> visited;

void dfs(int left, int right, const string& cur, set<string>& parts) {
    if (cur.size() >= s.size()) {
        if (cur == s) visited.insert(parts);
        return;
    }

    if (left - 1 >= 0) {
        string nxt = string(1, s[left - 1]) + cur;
        parts.insert(nxt);
        dfs(left - 1, right, nxt, parts);
        parts.erase(nxt);
    }

    if (right + 1 < (int)s.size()) {
        string nxt = cur + string(1, s[right + 1]);
        parts.insert(nxt);
        dfs(left, right + 1, nxt, parts);
        parts.erase(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    for (int i = 0; i < (int)s.size(); ++i) {
        string cur(1, s[i]);
        set<string> parts = {cur};
        dfs(i, i, cur, parts);
    }

    cout << visited.size();
    return 0;
}