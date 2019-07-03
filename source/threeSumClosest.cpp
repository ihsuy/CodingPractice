#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <list>
#include <chrono>
#include <random>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <bitset>
#include <fstream>
#include <string>

typedef long long ll;
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int>& nums, int target) {
    // sort so "two pointer" tactic is applicable
    sort(nums.begin(), nums.end());
    // store "ans" for the smallest "diff"
    int ans = 0, diff = INT_MAX;
    // try to use every element in "nums" as the first number in 3Sum
    for (int i = 0; i < nums.size() - 2; ++i) {
        // given first number, simplify 3Sum to 2Sum
        // update new target: "tar"
        // "cv" is used to store the closest 2Sum
        int tar = target - nums[i], cv;
        // "two pointer" to find smallest difference "dif"
        for (int l = i + 1, r = nums.size() - 1, dif = INT_MAX; l < r;) {
            int s = nums[l] + nums[r], d = abs(tar - s);
            if (d < dif) {
                dif = d;
                cv = s;
            }
            if (s > tar) r--;
            else if (s < tar) l++;
            else return target;
        }
        // use the closest 2Sum to try to update the closest 3Sum
        auto temp = abs(nums[i] + cv - target);
        if (temp < diff) {
            diff = temp;
            ans = nums[i] + cv;
        }
    }
    return ans;
}

int main()
{


    return 0;
}
