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
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

int helper(vector<int>& nums, const int& val, const int& i)
{	// recursively proceed in the vector
	// and whenever seeing a element thats larger
	// we make a choice: to include it or to not include it
	// and we pick the choice that yields larger result
	
	if(i == nums.size())
	{
		return 0;
	}

	if(nums[i] > val)
	{
		// include it
		int res1 = helper(nums, nums[i], i+1)+1;

		// not include it
		int res2 = helper(nums, val, i+1);

		return max(res1, res2);
	}

	return helper(nums, val, i+1);
}

int lengthOfLIS(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}

	int result = 1;

	int current_min = INT_MAX;

	for (int i = 0; i < nums.size()-1; ++i)
	{
		if(nums[i] < current_min)
		{
			current_min = nums[i]; 
			result = max(result, helper(nums, nums[i], i+1)+1);
		}
	}

	return result;
}

int main()
{
	vector<int> v {10, 9, 2, 5, 3, 7, 101, 18};

	cout << lengthOfLIS(v) << '\n';

	return 0;
}
