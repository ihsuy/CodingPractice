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
Given a string, your task is to count how many palindromic substrings in this
string.

The substrings with different start indexes or end indexes are counted as
different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/

// for every string of length N, there're 2*N-1 centers for its potential palindromic substrings
// i.e. for "aba" we have: a, space-between-a-b, b, space-between-b-a, a. 5 of them.
// then for each such center, we try to examine if there's palindromes formed around them
int countSubstrings(const string& s) {
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        int radius = (s.length() - i - 1 < i) ? s.length() - i - 1 : i;
        int low = i - radius, high = i + radius, count = 0;
        for (int l = low, h = high; l <= h; ++l, --h) {
            if (s[l] == s[h]) {
                count++;
            } else {
                count = 0;
            }
        }
        res += count;
        if (i != s.length() - 1) {
            high++;
            count = 0;
            for (int l = low, h = high; l < h; ++l, --h) {
                if (s[l] == s[h]) {
                    count++;
                } else {
                    count = 0;
                }
            }
            res += count;
        }
    }
    return res;
}

int main() {
    return 0;
}
