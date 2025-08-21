#include <iostream>
#include <set>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool laptop[41][41];
int n, m, k;

vector<vector<bool>> rotate(int r, int c, const vector<vector<bool>>& shape) {
    int new_r = c;
    int new_c = r;
    vector<vector<bool>> new_shape(new_r, vector<bool>(new_c));

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            new_shape[j][r-i-1] = shape[i][j];
        }
    }

    // cout << "=============before==================\n";
    // for(int i=0; i<r; i++) {
    //     for(int j=0; j<c; j++) {
    //         cout << shape[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "=============after==================\n";
    // for(int i=0; i<new_r; i++) {
    //     for(int j=0; j<new_c; j++) {
    //         cout << new_shape[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return new_shape;
}

bool cmp(int sX, int sY, const vector<vector<bool>>& shape) {
    int r = shape.size();
    int c = shape[0].size();

    if(n-sX < r || m-sY < c) return false;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(shape[i][j]) {
                if(laptop[sX+i][sY+j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void paste(int sX, int sY, const vector<vector<bool>>& shape) {
    int r = shape.size();
    int c = shape[0].size();

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(shape[i][j]) {
                laptop[sX+i][sY+j] = true;
            }
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    memset(laptop, false, sizeof(laptop));

    vector<vector<vector<bool>>> stickers;

    for(int i=0; i<k; i++) {
        int r, c;
        cin >> r >> c;

        vector<vector<bool>> shape(r, vector<bool>(c));
        int tmp;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                cin >> tmp;
                if(tmp == 1) shape[i][j] = true;
                else shape[i][j] = false;
            }
        }
        stickers.push_back(shape);
    }

    for(int i=0; i<stickers.size(); i++) {
        vector<vector<bool>> stkr = stickers[i];
        bool success = false;

        int rcount = 0;
        while(rcount<4 && !success) {
            vector<vector<bool>> cur = stkr;
            for (int t = 0; t < rcount; ++t) {
                cur = rotate((int)cur.size(), (int)cur[0].size(), cur);
            }
            for(int x=0; x<n; x++) {
                if(success) break;
                for(int y=0; y<m; y++) {
                    if(success) break;
                    if(cmp(x, y, cur)) {
                        success = true;
                        paste(x, y, cur);
                        break;
                    }
                }
            }
            rcount++;
        }
    }
    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {

            if(laptop[i][j]) {
                // cout << 1 << " ";
                cnt++;
            }
            else {
                // cout << 0 << " ";
            }
        }
        // cout << "\n";
    }
    cout << cnt;

}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}
