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


// solution 1 recursive with memorization
int helper(vector<int>& nums, const int& prev_i, const int& i,
           int** buffer)
{	// recursively proceed in the vector
	// and whenever seeing a element thats larger than the previous prev_value
	// we make a choice: to include it or to not include it
	// and we pick the choice that yields larger result

	if (i == nums.size())
	{
		return 0;
	}
	// the index of first dimention of buffer
	// is "shifted"
	if (buffer[prev_i + 1][i] != -1)
	{
		return buffer[prev_i + 1][i];
	}

	int res1 = 0, res2 = 0;

	if (prev_i < 0 or nums[i] > nums[prev_i])
	{	// if prev_i is -1, i.e. prev element is the first element
		// or when we see a larger element
		// include ith element it anyway
		res1 = helper(nums, i, i + 1, buffer) + 1;
	}
	// case2: do not include ith element
	res2 = helper(nums, prev_i, i + 1, buffer);

	// compare and get the greater result
	res1 = max(res1, res2);
	// memorization
	buffer[prev_i + 1][i] = res1;

	return res1;
}

int lengthOfLIS_memorization(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	// prepare buffer
	int** buffer = new int*[nums.size() + 1];
	for (int i = 0; i < nums.size(); ++i)
	{
		buffer[i] = new int[nums.size()];
		memset(buffer[i], -1, sizeof(int)*nums.size());
	}

	// begin from -1 meaning the first entry of
	// array could be included or not
	return helper(nums, -1, 0, buffer);
}

// solution 2 dynamic programming
// 10,9,2,5,3,7,101,18
// 1  1 1 2 2 3 4   4
int lengthOfLIS_dp(vector<int>& nums)
{	// use the fact that for every element in array nums
	// LIS in nums[0, current_pos] is the length of
	// the longest LIS for the largest element
	// that's smaller than the current element and locates before it
	int* dp = new int[nums.size()];
	memset(dp, 0, sizeof(int)*nums.size());

	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		int maxlen = 0;
		for (int j = 0; j < i; ++j)
		{
			if (nums[j] < nums[i])
			{	// find the largest dp in all elements
				// on the left of i and are smaller than nums[i]
				maxlen = max(maxlen, dp[j]);
			}
		}

		dp[i] = maxlen + 1;
		// result should be updated everytime when new dp is produced
		result = max(result, dp[i]);
	}

	return result;
}


int main()
{
	vector<int> v {10, 9, 2, 5, 3, 7, 101, 18, 16};

	cout << lengthOfLIS_memorization(v) << '\n';
	cout << lengthOfLIS_dp(v) << '\n';

	return 0;
}
