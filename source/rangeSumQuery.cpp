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
Given an integer array nums, find the sum of the
elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
   public:
    vector<int> runningSum, n;
    NumArray(vector<int>& nums) : n(nums), runningSum(nums) {
        for (int i = 1; i < nums.size(); ++i) {
            runningSum[i] += runningSum[i - 1];
        }
    }

    int sumRange(const int& i, const int& j) {
        return (n[i] - runningSum[i]) + runningSum[j];
    }
};

int main() {
    return 0;
}
