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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;

    int rows = matrix.size();

    if (rows == 0) {
        return vector<int>();
    }

    int cols = matrix[0].size();

    int r = 0, c = 0;
    int upperRight_r = 0, upperRight_c = cols - 1, lowerRight_r = rows - 1,
        lowerRight_c = cols - 1, lowerLeft_r = rows - 1, lowerLeft_c = 0,
        upperLeft_r = 0, upperLeft_c = 0;

    r = upperLeft_r;
    c = upperLeft_c;

    while (true) {
        // inspect<vector<int>>(result.begin(), result.end());
        // from upper left to upper right
        while (c != upperRight_c) {
            result.push_back(matrix[r][c]);
            c++;
        }

        // update upperleft corner position
        upperLeft_r++;
        if (upperLeft_r != 1) {
            upperLeft_c++;
        }

        if (result.size() == rows * cols - 1) {
            result.push_back(matrix[r][c]);
            break;
        }

        // from upper right to lower right
        while (r != lowerRight_r) {
            result.push_back(matrix[r][c]);
            r++;
        }

        // update upper right corner position
        upperRight_r++;
        upperRight_c--;

        // from lower right to lower left
        while (c != lowerLeft_c) {
            result.push_back(matrix[r][c]);
            c--;
        }

        if (result.size() == rows * cols - 1) {
            result.push_back(matrix[r][c]);
            break;
        }

        // update lower right corner position
        lowerRight_r--;
        lowerRight_c--;

        // from lower left to upper left
        while (r != upperLeft_r) {
            result.push_back(matrix[r][c]);
            r--;
        }

        // update lower left corner position
        lowerLeft_r--;
        lowerLeft_c++;
    }

    return result;
}

vector<int> spiralOrder_concise(vector<vector<int>>& matrix) {
    vector<int> result;
    int rows = matrix.size();

    if (rows == 0) {
        return result;
    }

    int cols = matrix[0].size();

    int br = 0, tr = rows - 1;
    int bc = 0, tc = cols - 1;

    while (br <= tr and bc <= tc) {
        for (int c = bc; c <= tc; ++c) {
            result.push_back(matrix[br][c]);
        }

        for (int r = br + 1; r <= tr; ++r) {
            result.push_back(matrix[r][tc]);
        }

        if (br >= tr or bc >= tc) {
            break;
        }

        for (int c = tc - 1; c > bc; --c) {
            result.push_back(matrix[tr][c]);
        }

        for (int r = tr; r > br; --r) {
            result.push_back(matrix[r][bc]);
        }

        br++;
        bc++;
        tr--;
        tc--;
    }

    return result;
}

int main() {
    vector<vector<int>> m{{1, 2, 3, 4}

    };

    auto result = spiralOrder_concise(m);

    inspect<vector<int>>(result.begin(), result.end());

    return 0;
}
