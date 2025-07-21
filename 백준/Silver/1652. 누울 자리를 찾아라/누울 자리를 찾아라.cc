/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> v(n);
    char c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c;
            if(c == 'X')
                v[i].push_back(false);
            else
                v[i].push_back(true);
        }
    }

    int row = 0, col = 0;
    for(int i=0; i<n; i++){
        int j=0;
        while(j<n){
            int start = j;
            while(j<n && v[i][j] == true) 
                j++;
            if(j-start-1 > 0) 
                row++;
            j++;
        }
    }

    for(int i=0; i<n; i++){
        int j=0;
        while(j<n){
            int start = j;
            while(j<n && v[j][i] == true) 
                j++;
            if(j-start-1 > 0) 
                col++;
            j++;
        }
    }


    cout << row << " " << col << "\n";
    return 0;
}