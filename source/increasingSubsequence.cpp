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
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/


set<vector<int>> results;
void helper(vector<int>& nums, const int& i, vector<int>& s)
{
    if (s.size() > 1)
    {
        results.insert(s);
    }

    for (int j = i; j < nums.size(); ++j)
    {
        if (s.empty() or s.back() <= nums[j])
        {
            s.push_back(nums[j]);
            helper(nums, j + 1, s);
            s.pop_back();
        }
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> s;
    helper(nums, 0, s);
    return vector<vector<int>>(results.begin(), results.end());
}

int main()
{
    vector<int> nums { -8, 28, 68, -54, 96, 97, 84, -32, 8, -87, 1, -7, -20, 12, 22};
    auto res = findSubsequences(nums);
    cout << res.size() << endl;
    // for (int i = 0; i < res.size(); ++i)
    // {
    //     inspect<vector<int>>(res[i]);
    //     cout << "\n";
    // }


    return 0;
}
