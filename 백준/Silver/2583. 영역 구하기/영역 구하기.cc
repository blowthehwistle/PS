/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, K;
void bfs(vector<vector<int8_t>> &v, int x, int y, int cnt){
    queue<pair<int8_t,int8_t>> q;
    v[x][y] = cnt;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i+1 < m && v[i+1][j] == 0){
            v[i+1][j] = cnt;
            q.push(make_pair(i+1, j));
        }
        if(i-1 >= 0 && v[i-1][j] == 0){
            v[i-1][j] = cnt;
            q.push(make_pair(i-1, j));
        }
        if(j+1 < n && v[i][j+1] == 0){
            v[i][j+1] = cnt;
            q.push(make_pair(i, j+1));
        }
        if(j-1 >= 0 && v[i][j-1] == 0){
            v[i][j-1] = cnt;
            q.push(make_pair(i, j-1));
        }
    }
    
}

int main()
{
    cin >> m >> n >> K;
    
    vector<vector<int8_t>> v(m, vector<int8_t>(n));
    
    for(int i=0; i<K; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j=b; j<d; j++){
            for(int l=a; l<c; l++){
                if(j < m && l < n){
                    v[j][l] = -1;
                }
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == 0){
                bfs(v, i, j, ++cnt);
            }
        }
    }
    vector<int> answer(cnt+1);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] > 0){
                int value = v[i][j];
                answer[value]++;
            }
        }
    }
    cout << cnt << "\n";
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<=cnt; i++){
        if(answer[i] > 0)
            pq.push(answer[i]);
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    
    
    cout << "\n";
    return 0;
    
}