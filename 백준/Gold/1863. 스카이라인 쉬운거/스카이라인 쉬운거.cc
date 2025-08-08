#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        int x, y; 
        cin >> x >> y;
        h[i] = y; 
    }

    long long cnt = 0;           
    vector<int> st; 
    st.reserve(N);

    for (int y : h) {
        while (!st.empty() && st.back() > y) {
            if (st.back() != 0) ++cnt;
            st.pop_back();
        }

        if (!st.empty() && st.back() == y) continue;

        if (y != 0) st.push_back(y);
    }

    while (!st.empty()) {
        if (st.back() != 0) ++cnt;
        st.pop_back();
    }

    cout << cnt;
    return 0;
}