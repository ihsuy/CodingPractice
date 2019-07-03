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
Given a file and assume that you can only read the file using a
given method read4, implement a method to read n characters.
*/

// Forward declaration of the read4 API.
int read4(char* buf);

class Solution {
   public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) {
        int nRead = n / 4;
        int remainder = n % 4;

        char* temp = buf;

        for (int i = 0; i < nRead; ++i) {
            auto r = read4(buf);
            if (r < 4) {
                return i * 4 + r;
            }
            buf += 4;
        }
        if (remainder != 0) {
            auto r = read4(buf);
            if (r < remainder) {
                *(temp + nRead * 4 + r) = 0;
                return nRead * 4 + r;
            }
            *(temp + n) = 0;
        }
        return n;
    }
};

int main() {
    // test cases omitted

    return 0;
}
