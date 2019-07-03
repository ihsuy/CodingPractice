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
Given a non negative integer number num. For every numbers i in the range 0 ≤ i
≤ num calculate the number of 1's in their binary representation and return them
as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass? Space
complexity should be O(n). Can you do it like a boss? Do it without using any
builtin function like __builtin_popcount in c++ or in any other language.
*/

vector<int> countBits(const int& num) {
    vector<int> res(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}

int main() {
    return 0;
}
