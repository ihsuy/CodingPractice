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
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that
row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a
binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.



Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39


Note:

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] is 0 or 1.
*/

enum TARGET { ROW, COL };
int r = 0, c = 0;
void toggle(TARGET tar, const int& i, vector<vector<int>>& A) {
    if (tar == ROW) {
        for (int j = 0; j < c; ++j) {
            A[i][j] ^= 1;
        }
    } else {
        for (int j = 0; j < r; ++j) {
            A[j][i] ^= 1;
        }
    }
}
int matrixScore(vector<vector<int>>& A) {
    r = A.size(), c = A[0].size();
    for (int i = 0; i < r; ++i) {
        if (A[i][0] == 0) {
            toggle(ROW, i, A);
        }
    }

    for (int i = 1; i < c; ++i) {
        int ones = 0;
        for (int j = 0; j < r; ++j) {
            if (A[j][i]) {
                ones++;
            }
        }
        if (ones * 2 < r) {
            toggle(COL, i, A);
        }
    }
    int res = 0;
    for (auto& row : A) {
        string b;
        for (auto& ch : row) {
            b += ch + '0';
        }
        bitset<32> bs(b);
        res += bs.to_ulong();
    }
    return res;
}

int main() {
    return 0;
}
