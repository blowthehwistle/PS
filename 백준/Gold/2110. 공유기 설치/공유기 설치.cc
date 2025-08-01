#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    int left = 1;                         // 최소 거리 (1 이상)
    int right = pos[n - 1] - pos[0];      // 최대 거리
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;     // 공유기 간 거리 후보
        int count = 1;                    // 설치된 공유기 수
        int last_installed = pos[0];      // 첫 번째 공유기 설치

        for (int i = 1; i < n; ++i) {
            if (pos[i] - last_installed >= mid) {
                count++;
                last_installed = pos[i];
            }
        }

        if (count >= c) {
            answer = mid;                // 더 넓은 간격 가능성 있음
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}