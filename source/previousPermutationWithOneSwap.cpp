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
Given an array A of positive integers (not necessarily distinct), return the
lexicographically largest permutation that is smaller than A, that can be made
with one swap (A swap exchanges the positions of two numbers A[i] and A[j]).  If
it cannot be done, then return the same array.



Example 1:

Input: [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.
Example 2:

Input: [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.
Example 3:

Input: [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.
Example 4:

Input: [3,1,1,3]
Output: [1,3,1,3]
Explanation: Swapping 1 and 3.


Note:

1 <= A.length <= 10000
1 <= A[i] <= 10000
*/

vector<int> prevPermOpt1(vector<int>& A) {
    int b = A.size() - 2;
    for (int i = b; i >= 0; --i) {
        int temp = -1, index = i;
        for (int j = A.size() - 1; j > i; --j) {
            if (A[j] >= temp and A[j] < A[i]) {
                temp = A[j];
                index = j;
            }
        }
        if (index != i) {
            swap(A[i], A[index]);
            break;
        }
    }
    return A;
}

int main() {
    vector<int> a{3, 1, 1, 3};
    auto res = prevPermOpt1(a);
    inspect<vector<int>>(res);

    return 0;
}
