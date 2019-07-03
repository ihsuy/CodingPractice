#include <math.h>
#include <algorithm>
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
inline void inspect(typename T::iterator i1, typename T::iterator i2) {
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> result;
    for (int i = 1; i <= n; ++i) {
        string msg;
        bool isMultiple3 = (i % 3 == 0);
        bool isMultiple5 = (i % 5 == 0);
        if (isMultiple3) {
            msg += "Fizz";
        }
        if (isMultiple5) {
            msg += "Buzz";
        }

        if (not(isMultiple3 or isMultiple5)) {
            msg += to_string(i);
        }

        result.push_back(msg);
    }

    return result;
}

int main() {
    vector<string> fb = fizzBuzz(200);
    inspect<vector<string>>(fb.begin(), fb.end());

    return 0;
}
