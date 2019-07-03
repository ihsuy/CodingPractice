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
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return "";
    } else if (strs.size() == 1) {
        return strs[0];
    }

    int sz = strs.size(), len = 0;
    for (int k = 0, i = 0;; ++k) {
        for (i = 0; i < sz - 1; ++i) {
            if (k >= strs[i].length() or k >= strs[i + 1].length() or
                strs[i][k] != strs[i + 1][k]) {
                return strs[0].substr(0, len);
            }
        }
        if (i == sz - 1) {
            len++;
        }
    }
    return strs[0].substr(0, len);
}

int main() {
    vector<string> strs{"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;

    return 0;
}
