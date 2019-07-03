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
By now, you are given a secret signature consisting of character
'D' and 'I'. 'D' represents a decreasing relationship between two
numbers, 'I' represents an increasing relationship between two
numbers. And our secret signature was constructed by a special
integer array, which contains uniquely all the different number
 from 1 to n (n is the length of the secret signature plus 1).
 For example, the secret signature "DI" can be constructed by
 array [2,1,3] or [3,1,2], but won't be constructed by array
 [3,2,4] or [2,1,3,4], which are both illegal constructing
 special string that can't represent the "DI" secret signature.

On the other hand, now your job is to find the lexicographically
smallest permutation of [1, 2, ... n] could refer to the given secret
signature in the input.

Example 1:
Input: "I"
Output: [1,2]
Explanation: [1,2] is the only legal initial spectial
string can construct secret signature "I", where the
number 1 and 2 construct an increasing relationship.
Example 2:
Input: "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can construct
the secret signature "DI",
but since we want to find the one with the smallest
lexicographical permutation, you need to output [2,1,3]
*/

vector<int> findPermutation(const string& s) {
    int len = s.length() + 1;
    vector<int> nums(len, 1);
    for (int i = 1; i < len; ++i) {
        nums[i] += nums[i - 1];
    }

    for (int i = 0, prev = 0; i < s.length(); ++i) {
        if (i == s.length() - 1 or s[i] != s[i + 1]) {
            if (s[i] == 'D') {
                reverse(nums.begin() + prev, nums.begin() + i + 2);
            }
            prev = i + 1;
        }
    }

    return nums;
}

int main() {
    string s = "DDIDD";
    auto res = findPermutation(s);
    inspect<vector<int>>(res);
    return 0;
}
