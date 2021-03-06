#include <math.h>
#include <algorithm>
#include <bitset>
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
Given an array, rotate the array to the right by k steps, where k is
non-negative.
*/
// [1,2,3,4,5,6,7] 3
// [5,6,7,1,2,3,4]

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    if (len <= 1 or k % len == 0) {
        return;
    }

    k %= len;

    vector<int> result;
    result.reserve(len);

    for (int i = len - k; i != len - k - 1; i = (i + 1) % len) {
        result.push_back(nums[i]);
    }
    result.push_back(nums[len - k - 1]);

    nums = result;
}

void rotate2(vector<int>& nums, int k) {
    int len = nums.size();
    if (len <= 1 or k % len == 0) {
        return;
    }

    k %= len;

    vector<int> result(len);

    copy(nums.begin() + len - k, nums.end(), result.begin());
    copy(nums.begin(), nums.begin() + len - k, result.begin() + k);

    nums = result;
}

void rotate3(vector<int>& nums, int k) {  // circulate swap
    int len = nums.size();

    if (len <= 1 or k % len == 0) {
        return;
    }

    k %= len;

    int count = 0;

    for (int i = 0; count < len; ++i) {
        int current = i;
        int prev = nums[current];
        do {
            int next = (current + k) % len;
            int temp = nums[next];
            nums[next] = prev;
            prev = temp;
            current = next;

            count++;
        } while (i != current);
    }
}

void rotate3_1(vector<int>& nums, int k) {  // circulate swap
    int len = nums.size();

    if (len <= 1 or k % len == 0) {
        return;
    }

    k %= len;

    int count = 0;

    for (int start = 0; count < nums.size(); start++) {
        int current = start;

        int prev = nums[start];

        do {
            int next = (current + k) % len;

            int temp = nums[next];

            nums[next] = prev;
            prev = temp;
            current = next;

            count++;
        } while (start != current);
    }
}

void rotate4(vector<int>& nums, int k) {
    auto iteb = nums.begin();
    auto itee = nums.end();
    auto itek = iteb + k;
    reverse(iteb, itee);
    reverse(iteb, itek);
    reverse(itek, itee);
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    rotate4(v, 2);

    inspect<vector<int>>(v);

    return 0;
}
