#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    int b, c;
    long long answer = 0;
    cin >> n;
    vector<int> v;
    int temp;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    cin >> b >> c;

    for(int i=0; i<n; i++){
        answer++;
        int remain = v[i]-b;
        if(remain > 0){
            if(remain % c > 0){
                answer += remain/c + 1;
            }else{
                answer += remain/c;
            }
        }
    }

    cout << answer;
    return 0;
}