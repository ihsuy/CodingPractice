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
Given an array of integers and an integer k,
you need to find the total number of continuous subarrays whose sum equals to k.
*/

int subarraySum(const vector<int>& nums, int k) {
    int runningSum = 0;
    unordered_map<int, int> lookups;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        runningSum += nums[i];

        int v = nums[i] - runningSum;

        int target = k - runningSum;

        if (lookups.count(v) == 0) {
            lookups[v] = 1;
        } else {
            lookups[v]++;
        }

        if (lookups.count(target) != 0) {
            result += lookups[target];
        }
    }
    return result;
}

int main() {
    // Input:nums = [1,1,1], k = 2
    // Output: 2

    return 0;
}
