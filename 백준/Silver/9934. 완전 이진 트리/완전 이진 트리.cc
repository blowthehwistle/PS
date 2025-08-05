
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <cmath>
using namespace std;

int k;
vector<pair<int, int>> ordr;
void preorder(int i, int j) {
    if(i != k-1 && j*2 < pow(2, i+1)){
        preorder(i+1, j*2);
    }
    ordr.push_back(make_pair(i, j));
    if(i != k-1 && j*2+1 < pow(2, i+1)){
        preorder(i+1, j*2+1);
    }
}

void solve(){
    cin >> k;
    vector<vector<int>> v(k);
    // vector<pair<int, int>> l(k+1);
    // vector<pair<int, int>> r(k+1);

    int n = pow(2, k)-1;

    for(int i=0; i<k; i++) {
        for(int j=0; j<pow(2, i); j++) {
            v[i].push_back(0);
        }
    }
    //
    preorder(0, 0);

    vector<int> in_seq;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        in_seq.push_back(temp);
    }

    for(int i=0; i<ordr.size(); i++) {
        int x = ordr[i].first;
        int y = ordr[i].second;

        v[x][y] = in_seq[i];
    }

    for(int i=0; i<k; i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
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