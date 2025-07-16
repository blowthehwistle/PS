#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double comb[21][21];

void init_comb() {
    for (int n = 0; n <= 20; ++n) {
        comb[n][0] = comb[n][n] = 1;
        for (int r = 1; r < n; ++r) {
            comb[n][r] = comb[n-1][r-1] + comb[n-1][r];
        }
    }
}

int main() {
    long double w, l, d;
    cin >> w >> l >> d;

    init_comb();

    long double bronze = 0, silver = 0, gold = 0, plat = 0, dia = 0;

    for (int win = 0; win <= 20; ++win) {
        for (int lose = 0; lose <= 20 - win; ++lose) {
            int draw = 20 - win - lose;

            int score = 2000 + 50 * win - 50 * lose;

            long double prob = comb[20][win] * comb[20 - win][lose]
                             * pow(w, win) * pow(l, lose) * pow(d, draw);

            if (score <= 1499) bronze += prob;
            else if (score <= 1999) silver += prob;
            else if (score <= 2499) gold += prob;
            else if (score <= 2999) plat += prob;
            else if (score <= 3499) dia += prob;
        }
    }

    cout << fixed << setprecision(8);
    cout << bronze << "\n";
    cout << silver << "\n";
    cout << gold << "\n";
    cout << plat << "\n";
    cout << dia << "\n";

    return 0;
}