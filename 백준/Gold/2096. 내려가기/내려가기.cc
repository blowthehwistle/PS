
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

int n;

int main()
{
    cin >> n;

    vector<int> dpmax_prev(3);
    vector<int> dpmin_prev(3);
    vector<int> dpmax_cur(3);
    vector<int> dpmin_cur(3);
    vector<int> inp(3);

    for(int i=0; i<n; i++){
        cin >> inp[0] >> inp[1] >> inp[2];

        for(int j=0; j<3; j++){
            if(i == 0) {
                dpmax_prev[j] = inp[j];
                dpmax_cur[j] = inp[j];
                dpmin_prev[j] = inp[j];
                dpmin_cur[j] = inp[j];
                continue;
            }

            int localmax = INT_MIN, localmin = INT_MAX;
            if(j-1 >= 0){
                localmax = max(localmax, dpmax_prev[j-1]);
                localmin = min(localmin, dpmin_prev[j-1]);
            }
            localmax = max(localmax, dpmax_prev[j]);
            localmin = min(localmin, dpmin_prev[j]);
            if(j+1 < 3){
                localmax = max(localmax, dpmax_prev[j+1]);
                localmin = min(localmin, dpmin_prev[j+1]);
            }
            dpmax_cur[j] = inp[j] + localmax;
            dpmin_cur[j] = inp[j] + localmin;
        }

        dpmax_prev = dpmax_cur;
        dpmin_prev = dpmin_cur;
    }


    cout << max(max(dpmax_cur[0], dpmax_cur[1]), dpmax_cur[2]) << " " <<
    min(min(dpmin_cur[0], dpmin_cur[1]), dpmin_cur[2]) << "\n";
    return 0;

}