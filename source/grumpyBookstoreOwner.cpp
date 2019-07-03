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
Today, the bookstore owner has a store open for customers.length minutes.  Every
minute, some number of customers (customers[i]) enter the store, and all those
customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  If the bookstore owner is
grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the
bookstore owner is grumpy, the customers of that minute are not satisfied,
otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X
minutes straight, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.



Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3
minutes. The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 +
7 + 5 = 16.


Note:

1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1

*/

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, const int& x) {
    int res = 0, csize = customers.size();
    for (int i = 0; i < csize; ++i) {
        if (not grumpy[i]) {
            res += customers[i];
        }
    }
    int t = -1;
    for (int i = 0; i < csize - x + 1; ++i) {
        int temp = 0;
        for (int j = 0; j < x; ++j) {
            if (grumpy[i + j]) {
                temp += customers[i + j];
            }
        }
        if (temp > t) {
            t = temp;
        }
    }
    return res + t;
}

int main() {
    return 0;
}
