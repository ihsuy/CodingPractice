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
Given an array of integers A sorted in non-decreasing order, return an array of
the squares of each number, also in sorted non-decreasing order.



Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]


Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

vector<int> sortedSquares(vector<int>& A) {
    int first_nonneg = -1;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] >= 0) {
            first_nonneg = i;
            break;
        }
    }
    if (first_nonneg == 0) {
        for (auto& item : A) {
            item *= item;
        }
        return A;
    } else if (first_nonneg == -1) {
        for (auto& item : A) {
            item *= item;
        }
        reverse(A.begin(), A.end());
        return A;
    }
    vector<int> res;
    res.reserve(A.size());
    int i = first_nonneg - 1, j = first_nonneg;
    while (i >= 0 and j < A.size()) {
        if (abs(tempj) < abs(tempi)) {
            res.push_back(A[j] * A[j]);
            j++;
        } else {
            res.push_back(A[i] * A[i]);
            i--;
        }
    }

    if (i >= 0) {
        for (; i >= 0; --i) {
            res.push_back(A[i] * A[i]);
        }
    } else if (j != A.size()) {
        for (; j < A.size(); ++j) {
            res.push_back(A[j] * A[j]);
        }
    }
    return res;
}

int main() {
    return 0;
}
