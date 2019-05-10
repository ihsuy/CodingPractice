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
Given a non-empty array of non-negative integers nums,
the degree of this array is defined as the maximum
frequency of any one of its elements.

Your task is to find the smallest possible length of
a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
*/

int findShortestSubArray(vector<int>& nums) 
{
    unordered_map<int, pair<int, pair<int, int>>> m;
    int max_val = INT_MIN;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (m.count(nums[i]) == 0)
        {
            m.emplace(nums[i], pair<int, pair<int, int>> {1, {i, i}});
            if (max_val < 1) max_val = 1;
        }
        else
        {
            int& c = ++m[nums[i]].first;
            pair<int, int>& r = m[nums[i]].second;
            if (i < r.first) r.first = i;
            else if (i > r.second) r.second = i;

            if (c > max_val) max_val = c;
        }
    }
    int result = INT_MAX;
    for (const auto& obj : m)
    {
        if (obj.second.first == max_val)
        {
            auto tmp = obj.second.second.second - obj.second.second.first;
            if (tmp < result) result = tmp;
        }
    }
    return result + 1;
}

int main()
{


    return 0;
}
