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

vector<int> plusOne(vector<int>& digits) {
    if (digits.size() == 0) {
        return digits;
    }

    vector<int> result(digits.size() + 1, 0);

    int s = 0, carry = 1;

    for (int i = digits.size() - 1; i >= 0; --i) {
        s = digits[i] + carry;
        carry = s / 10;
        s %= 10;

        result[i + 1] = s;
    }
    if (carry) {
        result[0] = 1;
    } else {
        result.erase(result.begin());
    }
    return result;
}

vector<int>& plusOne_inplace(vector<int>& digits) {
    if (digits.size() == 0) {
        return digits;
    }

    int s = 0, carry = 1;

    for (int i = digits.size() - 1; i >= 0; --i) {
        s = digits[i] + carry;
        carry = s / 10;
        s %= 10;

        digits[i] = s;
    }
    if (carry) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main() {
    vector<int> n{9, 9, 9, 9, 9, 9, 9};
    auto n1 = plusOne(n);

    inspect<vector<int>>(n1.begin(), n1.end());

    return 0;
}
