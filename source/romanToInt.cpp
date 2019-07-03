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

int romanToInt(string s) {
    int len = s.length();

    int cd = 400, cm = 900, xl = 40, xc = 90, iv = 4, ix = 9;

    int result = 0;

    for (int i = 0; i < len; ++i) {
        char curr = s[i];
        bool hasNext = (i != len - 1);

        switch (curr) {
            case 'M':
                result += 1000;
                break;
            case 'D':
                result += 500;
                break;
            case 'C': {
                if (hasNext) {
                    char next = s[i + 1];

                    if (next == 'D') {
                        result += cd;
                        i++;
                    } else if (next == 'M') {
                        result += cm;
                        i++;
                    } else {
                        result += 100;
                    }
                } else {
                    result += 100;
                }
                break;
            }
            case 'L':
                result += 50;
                break;
            case 'X': {
                if (hasNext) {
                    char next = s[i + 1];

                    if (next == 'L') {
                        result += xl;
                        i++;
                    } else if (next == 'C') {
                        result += xc;
                        i++;
                    } else {
                        result += 10;
                    }
                } else {
                    result += 10;
                }
                break;
            }
            case 'V':
                result += 5;
                break;
            case 'I': {
                if (hasNext) {
                    char next = s[i + 1];

                    if (next == 'V') {
                        result += iv;
                        i++;
                    } else if (next == 'X') {
                        result += ix;
                        i++;
                    } else {
                        result += 1;
                    }
                } else {
                    result += 1;
                }
            }
        }
    }
    return result;
}
int main() {
    const string n = "IV";

    cout << romanToInt(n) << endl;

    return 0;
}
