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

On the first row, we write a 0. Now in every subsequent row, we look at the
previous row and replace each occurrence of 0 with 01, and each occurrence of 1
with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of
K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
*/

int kthGrammar(int N, int K) {
    // Try to think this problem as if its a binary tree problem
    // that is, when are actually trying to know the K-th leaf on N th level of
    // a binary tree Also notice that, if K is odd, then its the same as its
    // "parent", since "0"->"01" and "1"->"10", the first number is always the
    // same as the previous number and if K is even, the number is "flipped" we
    // could utilize this information to find how many time did the digit "flip"
    // as we traverse back to the top of the tree
    // XOR is good at detecting uneven alternations, i used it in the follow
    // solution
    if (N == 1)
        return 0;
    return (1 - K % 2) ^ kthGrammar(N - 1, (K + 1) >> 1);
}

int main() {
    return 0;
}
