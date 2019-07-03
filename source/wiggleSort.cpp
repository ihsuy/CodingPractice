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
Given an unsorted array nums, reorder it
in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]...
*/

void wiggleSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); ++i) {  // analysis by case:
        // assume the first i-1 elements of nums is already wigglelysorted
        // sort all i elements
        // the only two cases are if the ith element is less or equal to the
        // i-1th element or its larger than it which can be both solved by
        // simplely swapping the values of ith and i-1th

        if ((i % 2 == 1 and nums[i - 1] > nums[i]) or
            (i % 2 == 0 and nums[i - 1] < nums[i])) {
            swap(nums[i - 1], nums[i]);
        }
    }
}

int main() {
    vector<int> v{3, 5, 2, 1, 6, 4};

    wiggleSort(v);

    inspect<vector<int>>(v);

    return 0;
}
