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
Given two strings s and t, determine if they are both one edit distance apart.

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
*/

bool isOneEditDistance(string s, string t) {
    int larger_len = max(s.length(), t.length());
    int smaller_len = min(s.length(), t.length());

    if (larger_len - smaller_len > 1) {
        return false;
    }

    bool here = false;

    if (larger_len == smaller_len) {
        for (int i = 0, j = 0; i < s.length() and j < t.length(); ++i, ++j) {
            if (s[i] != t[j]) {
                if (here) {
                    return false;
                }
                here = true;
            }
        }
        return here;
    } else {
        for (int i = 0, j = 0; i < s.length() and j < t.length(); ++i, ++j) {
            if (s[i] != t[j]) {
                return (s.substr(i) == t.substr(j + 1)) or
                       (s.substr(i + 1) == t.substr(j));
            }
        }
    }
    return larger_len != smaller_len;
}

int main() {
    cout << isOneEditDistance("abc", "ab") << endl;

    return 0;
}
