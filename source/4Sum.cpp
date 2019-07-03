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
Given an array nums of n integers and an integer target, are there elements a,
b, c, and d in nums such that a + b + c + d = target? Find all unique
quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

unordered_map<int, pair<int, int>> r;
vector<pair<int, int>> twoSum(const vector<int>& nums,
                              const int& low,
                              const int& target) {
    vector<pair<int, int>> res;
    for (int i = low; i < nums.size() - 1;) {
        int tar = target - nums[i];
        if (r.count(tar) and r[tar].second > i) {
            res.push_back({nums[i], tar});
        }
        i = r[nums[i]].second + 1;
    }
    return res;
}
vector<vector<int>> fourSum(vector<int>& nums, const int& target) {
    if (nums.size() < 4)
        return {};
    else if (nums.size() == 4) {
        return ((nums[0] + nums[1] + nums[2] + nums[3]) == target)
                   ? vector<vector<int>>{nums}
                   : vector<vector<int>>();
    }
    vector<vector<int>> s;

    sort(nums.begin(), nums.end());

    r[nums.front()].first = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            r[nums[i]].first = i;
            r[nums[i - 1]].second = i - 1;
        }
    }
    r[nums.back()].second = nums.size() - 1;

    for (int i = 0; i < nums.size() - 3;) {
        if ((nums[i] + nums[i] + nums[i + 1] + nums[i + 2]) > target)
            break;
        if ((nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] +
             nums[nums.size() - 3]) >= target) {
            for (int j = i + 1; j < nums.size() - 2;) {
                if ((nums[i] + nums[j] + nums[j + 1] + nums[j + 2]) > target)
                    break;
                if ((nums[i] + nums[j] + nums[nums.size() - 1] +
                     nums[nums.size() - 2]) >= target) {
                    int tar = target - nums[i] - nums[j];
                    auto temp = twoSum(nums, j + 1, tar);
                    for (auto& item : temp) {
                        s.push_back(
                            {nums[i], nums[j], item.first, item.second});
                    }
                }
                j = r[nums[j]].second + 1;
            }
        }
        i = r[nums[i]].second + 1;
    }
    return s;
}

int main() {
    return 0;
}
