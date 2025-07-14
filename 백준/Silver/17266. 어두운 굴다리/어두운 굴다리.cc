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
    int n, m;    
    cin >> n >> m;

    vector<int> v;
    int temp;
    for(int i=0; i<m; i++){
        cin >> temp;
        v.push_back(temp);
    }    
    
    int light = v[0];
    // if(v.size() == 1){
    //   light = max(v[0]-0, n-v[0]);  
    //   cout << light << "\n";
    //   return 0;
    // } 
    
    for(int i=0; i<v.size()-1; i++){
        while(v[i]+light < v[i+1]-light){
            light++;
        }
    }
    
    int size = v.size()-1;
    while(v[size]+light < n){
        light++;
    }
    
    cout << light << "\n";
    
    return 0;
}