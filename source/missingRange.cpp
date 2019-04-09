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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given a sorted integer array nums, where the
range of elements are in the inclusive range [lower, upper],
return its missing ranges.
Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
{
	if (nums.size() == 0)
	{
		if (upper == lower)
		{
			return {to_string(lower)};
		}
		else
		{
			return {to_string(lower) + "->" + to_string(upper)};
		}
	}

	vector<string> result;

	if (nums[0] != lower and nums[0] > lower + 1)
	{
		result.push_back(to_string(lower) + "->" + to_string(nums[0] - 1));
	}
	else if (nums[0] > lower)
	{
		result.push_back(to_string(lower));
	}

	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i - 1])
		{
			continue;
		}
		if (nums[i] > nums[i - 1] + 2)
		{
			result.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
		}
		else if (nums[i] > nums[i - 1] + 1)
		{
			result.push_back(to_string(nums[i - 1] + 1));
		}
	}

	if (upper !=  nums.back() and upper > nums.back() + 1)
	{
		result.push_back(to_string(nums.back() + 1) + "->" + to_string(upper));
	}
	else if (upper > nums.back())
	{
		result.push_back(to_string(upper));
	}

	return result;
}

int main()
{
	vector<int> nums{0, 1, 3, 50, 75};
	auto result = findMissingRanges(nums, 0, 99);

	inspect<vector<string>>(result);

	return 0;
}
