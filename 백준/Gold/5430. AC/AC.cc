#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string commands, arrayStr;
        int n;
        cin >> commands;
        cin >> n;
        cin >> arrayStr;

        deque<int> dq;
        string num = "";
        
        // 문자열을 정수 배열로 변환
        for (int i = 1; i < arrayStr.size(); ++i) {
            if (isdigit(arrayStr[i])) {
                num += arrayStr[i];
            } else if (arrayStr[i] == ',' || arrayStr[i] == ']') {
                if (!num.empty()) {
                    dq.push_back(stoi(num));
                    num.clear();
                }
            }
        }

        bool isReversed = false;
        bool isError = false;

        for (char c : commands) {
            if (c == 'R') {
                isReversed = !isReversed;
            } else if (c == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                }
                if (isReversed)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (isError) {
            cout << "error\n";
        } else {
            cout << "[";
            if (isReversed) {
                for (int i = dq.size() - 1; i >= 0; --i) {
                    cout << dq[i];
                    if (i != 0) cout << ",";
                }
            } else {
                for (int i = 0; i < dq.size(); ++i) {
                    cout << dq[i];
                    if (i != dq.size() - 1) cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}