#include <bits/stdc++.h>
using namespace std;

bool laptop[41][41];
int n, m, k;

vector<vector<bool>> rotate90(const vector<vector<bool>>& shape) {
    int r = (int)shape.size(), c = (int)shape[0].size();
    vector<vector<bool>> res(c, vector<bool>(r));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            res[j][r - i - 1] = shape[i][j]; 
    return res;
}

bool canPaste(int sX, int sY, const vector<vector<bool>>& shape) {
    int r = (int)shape.size(), c = (int)shape[0].size();
    if (sX + r > n || sY + c > m) return false; 
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (shape[i][j] && laptop[sX + i][sY + j]) return false;
    return true;
}

void doPaste(int sX, int sY, const vector<vector<bool>>& shape) {
    int r = (int)shape.size(), c = (int)shape[0].size();
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (shape[i][j]) laptop[sX + i][sY + j] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    memset(laptop, 0, sizeof(laptop));

    vector<vector<vector<bool>>> stickers(k);
    for (int s = 0; s < k; ++s) {
        int r, c; cin >> r >> c;
        stickers[s].assign(r, vector<bool>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                int x; cin >> x;
                stickers[s][i][j] = (x == 1);
            }
    }

    for (int s = 0; s < k; ++s) {
        vector<vector<bool>> cur = stickers[s];
        bool placed = false;

        for (int rot = 0; rot < 4 && !placed; ++rot) {
            int R = (int)cur.size(), C = (int)cur[0].size();

            for (int x = 0; x <= n - R && !placed; ++x) {
                for (int y = 0; y <= m - C && !placed; ++y) {
                    if (canPaste(x, y, cur)) {
                        doPaste(x, y, cur);
                        placed = true;
                    }
                }
            }

            if (!placed) cur = rotate90(cur); 
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (laptop[i][j]) ++cnt;

    cout << cnt << '\n';
    return 0;
}