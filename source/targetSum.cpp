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
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

int mcount = 0;
void helper(const vector<int>& nums, const int& i, const int& t, const int& s)
{
    if (i == nums.size())
    {
        if (t == s)
        {
            mcount++;
        }
        return;
    }
    helper(nums, i + 1, t + nums[i], s);
    helper(nums, i + 1, t - nums[i], s);
}
int findTargetSumWays(vector<int>& nums, const int& S) {
    helper(nums, 0, 0, S);
    return mcount;
}

int helper2(const vector<int>& nums, const int& i, const int& t, const int& s, vector<vector<int>>& buffer)
{
    if (i == nums.size())
    {
        if (t == s)
        {
            return 1;
        }
        return 0;
    }
    if (buffer[i][t+1000] != INT_MIN)
    {
        return buffer[i][t+1000];
    }

    auto c = helper2(nums, i + 1, t + nums[i], s, buffer)
             + helper2(nums, i + 1, t - nums[i], s, buffer);
    buffer[i][t+1000] = c;
    return c;
}
int findTargetSumWays2(vector<int>& nums, const int& S) {
    vector<vector<int>> buffer(nums.size() + 1, vector<int>(2001, INT_MIN));
    return helper2(nums, 0, 0, S, buffer);
}

int main()
{
    vector<int> nums {5, 40, 23, 47, 43, 19, 36, 10, 28, 46,
                      14, 11, 5, 0, 5, 22, 39, 30, 50, 41};
    cout << findTargetSumWays2(nums, 48) << '\n';
    return 0;
}
