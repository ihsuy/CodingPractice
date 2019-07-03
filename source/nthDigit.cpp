#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <fstream>
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

*/

int findNthDigit(int n) {
    if (n < 10) {
        return n;
    }
    long long k = 9, h = 1, d = 1, s = 9;
    while (s + k * h * 10 * (d + 1) <= n) {
        h *= 10;
        d++;
        s += k * h * d;
    }
    long long l = n - s, i = l / (d + 1), j = l % (d + 1),
              b = pow(10, d) + i - (j > 0 ? 0 : 1), g = j > 0 ? (d + 1 - j) : 0;
    while (g--) {
        b /= 10;
    }
    return b % 10;
}

int main() {
    for (int i = 1; i < 100000; ++i) {
        cout << findNthDigit(i);
    }

    return 0;
}
