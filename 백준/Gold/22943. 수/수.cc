#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int totalCount = 0;
int K, M;
bool usedDigits[10] = {false};

vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= limit; ++i)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

vector<bool> markAddablePrimes(const vector<int>& primes, int limit) {
    vector<bool> result(limit, false);

    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i + 1; j < primes.size(); ++j) {
            int sum = primes[i] + primes[j];
            if (sum < limit)
                result[sum] = true;
            else
                break;
        }
    }

    return result;
}

vector<bool> markMultipliablePrimes(const vector<int>& primes, int limit) {
    vector<bool> result(limit, false);

    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i; j < primes.size(); ++j) {
            long long product = (long long)primes[i] * primes[j];
            if (product < limit)
                result[(int)product] = true;
            else
                break;
        }
    }

    return result;
}

bool isValidNumber(int number, const vector<bool>& sumList, const vector<bool>& productList) {
    if (!sumList[number])
        return false;

    while (number % M == 0)
        number /= M;

    return productList[number];
}

void generateNumbers(int depth, int current, const vector<bool>& sumList, const vector<bool>& productList) {
    if (depth == K) {
        if (isValidNumber(current, sumList, productList))
            totalCount++;
        return;
    }

    for (int digit = 0; digit <= 9; ++digit) {
        if (usedDigits[digit]) continue;
        if (depth == 0 && digit == 0) continue; // 첫 자리에 0 금지

        usedDigits[digit] = true;
        generateNumbers(depth + 1, current * 10 + digit, sumList, productList);
        usedDigits[digit] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> K >> M;
    int maxValue = pow(10, K);

    auto primes = generatePrimes(maxValue);
    auto sumList = markAddablePrimes(primes, maxValue);
    auto productList = markMultipliablePrimes(primes, maxValue);

    generateNumbers(0, 0, sumList, productList);

    cout << totalCount;
    return 0;
}