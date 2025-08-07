#include <iostream>
#include <cmath>  

using namespace std;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int x, y;
        cin >> x >> y;

        int length = y - x;
        int d = sqrt(length);
        int move_count;

        if (pow(d, 2) == length) {
            move_count = 2 * d - 1;
        } else {
            move_count = 2 * d;
            if (length > d * (d + 1)) {
                move_count += 1;
            }
        }

        cout << move_count << "\n";
    }

    return 0;
}