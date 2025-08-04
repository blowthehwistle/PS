/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <set>
#include <queue>

using namespace std;

void solve(){
    int n, m;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    char k;
    
    // cin >> k;
    // while(k == '\n'){
    //     cin.ignore();
    //     cin >> k;
    // }
    cin >> n >> m;

    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        pq1.push(temp);
    }
    for(int j=0; j<m; j++){
        cin >> temp;
        pq2.push(temp);
    }
    
    while(!pq1.empty() && !pq2.empty()){
        int x = pq1.top();
        int y = pq2.top();
        
        if(x == y || y < x){
            pq2.pop();
        }
        if(x < y){
            pq1.pop();
        }
    }
    if(pq1.empty()){
        cout << "B" << "\n";
    }
    else if(pq2.empty()){
        cout << "S" << "\n";
    }
    else{
        cout << "C" << "\n";
    }
    
}
int main()
{
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
    
    
    return 0;
}