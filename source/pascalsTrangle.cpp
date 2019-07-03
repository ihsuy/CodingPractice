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
In Pascal's triangle, each number is the
sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

int getVal(const int& r, const int& c, const vector<vector<int>>& p) {
    if (c == 0 or r == c) {
        return 1;
    }
    return ((p[r - 1][c - 1] != 0) ? p[r - 1][c - 1]
                                   : getVal(r - 1, c - 1, p)) +
           ((p[r - 1][c] != 0) ? p[r - 1][c] : getVal(r - 1, c, p));
}
vector<vector<int>> generate(const int& n) {
    vector<vector<int>> p;
    for (int r = 0, uc = 1; r < n; ++r, ++uc) {
        vector<int> layer;
        for (int c = 0; c < uc; ++c) {
            layer.push_back(0);
        }
        p.push_back(layer);
    }
    for (int r = 0, uc = 1; r < n; ++r, ++uc) {
        for (int c = 0; c < uc; ++c) {
            p[r][c] = getVal(r, c, p);
        }
    }
    return p;
}

/*
Given a non-negative index k where k ≤ 33, return the kth
index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above
it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/

vector<int> getRow(int n) {
    if (n == 0) {
        return {1};
    }
    vector<int> row(n + 1, 0);
    row[0] = 1, row.back() = 1;
    auto prev = getRow(n - 1);
    for (int i = 1; i < n; ++i) {
        row[i] = prev[i - 1] + prev[i];
    }
    return row;
}

// solution with minimal extra space usage
vector<int> getRow(const int& n) {
    vector<int> row(n + 1, 1);
    for (int u = 1, ri = 1; u <= n; ++u) {
        for (int i = 1, temp = 1; i < u; temp = ri) {
            row[i++] = temp + (ri = row[i]);
        }
    }
    return row;
}

int main() {
    auto res = getRow2(33);
    inspect<vector<int>>(res);

    return 0;
}
