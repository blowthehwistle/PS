
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <cmath>
using namespace std;

vector<int> l(27);
vector<int> r(27);
vector<int> v(27);

void preorder(int x) {
    if(x == '.'-'A') return;
    cout <<(char)(x+'A');
    preorder(l[x]);
    preorder(r[x]);
}

void inorder(int x) {
    if(x == '.'-'A') return;
    inorder(l[x]);
    cout <<(char)(x+'A');
    inorder(r[x]);
}

void postorder(int x) {
    if(x == '.'-'A') return;
    postorder(l[x]);
    postorder(r[x]);
    cout <<(char)(x+'A');
}


void solve(){
    int n;
    cin >> n;

    queue<int> q;

    char a, b, c;
    for(int i=0; i<n; i++) {
        cin >> a >> b >> c;
        v[a-'A'] = a-'A';
        l[a-'A'] = b-'A';
        r[a-'A'] = c-'A';
    }


    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";

    postorder(0);
    cout << "\n";


}
int main()
{
    cin.tie(0);

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();


    return 0;
}