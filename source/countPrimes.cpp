#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
inline int two(int n) {
    return 1 << n;
}
inline int test(int n, int b) {
    return (n >> b) & 1;
}
inline void set_bit(int& n, int b) {
    n |= two(b);
}
inline void unset_bit(int& n, int b) {
    n &= ~two(b);
}
inline int last_bit(int n) {
    return n & (-n);
}
inline int ones(int n) {
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Count the number of prime numbers less than a non-negative number, n.
*/

int countPrimes(const int& n) {
    if (n <= 2) {
        return 0;
    }
    bool buffer[n + 1];
    memset(buffer, true, sizeof(buffer));

    int result = 0;
    int secret = 0;
    for (int i = 2; i * i < n; ++i) {
        if (buffer[i]) {
            for (int j = i * i; j < n; j += i) {
                buffer[j] = false;
            }
            result++;
            secret = i;
        }
    }

    for (int i = (secret == 0) ? 2 : secret + 1; i < n; ++i) {
        if (buffer[i])
            result++;
    }
    return result;
}

int main() {
    const int n = 100;
    cout << countPrimes(n) << '\n';

    return 0;
}
