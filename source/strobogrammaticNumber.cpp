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
A strobogrammatic number is a number that looks the same when
rotated 180 degrees (looked at upside down).
Write a function to determine if a number is strobogrammatic.
The number is represented as a string.
*/

bool isSymmetricDigit(
    const char& ch) {  // between 0-9 only 0 1 9 8 are not going to change after
                       // 180 degree rotation
    return (ch == '0' or ch == '1' or ch == '8');
}

bool isEither6or9(
    const char& ch1,
    const char& ch2) {  // 6 and 9 is a special case cause rotating
    // by 180 will cause their value to be swapped
    return (ch1 == '6' and ch2 == '9') or (ch1 == '9' and ch2 == '6');
}

bool isStrobogrammatic(string num) {
    int low = 0, high = num.length() - 1;
    while (low <= high) {
        if ((not isEither6or9(num[low], num[high])) and
            (num[low] != num[high] or
             (not isSymmetricDigit(
                 num[low])))) {  // a number is not a strobogrammatic number
                                 // when
            // it contains a number thats not symmtricDigit
            // and its not 6 or 9 or its counter part isn't 9 or 6 respectively
            return false;
        }

        low++;
        high--;
    }

    return true;
}

int main() {
    const string s1 = "692";
    const string s2 = "66199";

    cout << s1 << " isStrobogrammatic: " << isStrobogrammatic(s1) << '\n';
    cout << s2 << " isStrobogrammatic: " << isStrobogrammatic(s2) << '\n';

    return 0;
}
