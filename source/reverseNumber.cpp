#include <iostream>
#include <vector>
using namespace std;

const vector<long long> pow10{1,      10,      100,      1000,      10000,
                              100000, 1000000, 10000000, 100000000, 1000000000};

long long reverse(long long x) {
    if (x < 10 and x > -10) {
        return x;
    }

    long long result = 0;
    long long temp = x;
    while (temp != 0) {
        result = 10 * result + temp % 10;
        temp /= 10;
    }

    int test = result;
    if (test != result) {
        return 0;
    }

    return result;
}

int main() {
    const long long n = -34236469211;
    cout << reverse(n) << endl;

    return 0;
}