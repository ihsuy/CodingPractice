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
Given an unsorted integer array,
find the smallest missing positive integer.

Your algorithm should run in O(n) time and uses constant extra space.
*/

int firstMissingPositive_linearSpace(vector<int> nums)
{
	unordered_set<int> buffer;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] > 0)
		{
			buffer.insert(nums[i]);
		}
	}

	int minval = 1;

	while (buffer.count(minval))
	{
		minval++;
	}

	return minval;
}

int firstMissingPositive(vector<int> nums)
{	// preprocessing
	bool seen_one = false;
	
	for (int i = 0; i < nums.size(); ++i)
	{	// set every invalid number (number that are less than 1)
		// to 1
		// and check if there was originally any 1 in the array
		if (nums[i] <= 0)
		{
			nums[i] = 1;
		}
		else if (nums[i] == 1)
		{
			seen_one = true;
		}
	}

	if (not seen_one)
	{	// if no 1 was found
		// result is 1
		return 1;
	}

	// the key here is: 
	// we know, if we see a number that's larger than nums.size(),
	// the first missing positive integer will definitely be one of
	// 1~nums.size() inclusive
	// since otherwise in this case we don't have enough space to store
	// every consecutive number in nums 
	// (we need nums.size() space to store numbers from 1 to nums.size())
	// 
	// we can ignore any number that aren't in the range 1~nums.size()
	// and mark every number that is in range directly in the given array
	// by flipping the sign of nums[nums[i]-1] 
	// in other words, we use negative sign to indicate this number exists in nums

	// if 1 was already found, 
	// so we set the first element to negative
	nums[0] = -nums[0];


	for (int i = 0; i < nums.size(); ++i)
	{	// we still need to check the for number 
		// though its previously marked negative
		int idx = (nums[i] < 0) ? -nums[i] - 1 : nums[i] - 1;

		if (idx < nums.size() and nums[idx] > 0)
		{	// flip sign indicate "seen"
			nums[idx] = -nums[idx];
		}
	}

	for (int i = 0; i < nums.size(); ++i)
	{	// find the first positive entry and that's the answer
		if (nums[i] > 0)
		{
			return i + 1;
		}
	}

	// if no positive entry was found, 
	// it means there's missing integer in the range 1~nums.size()
	// then it must be the immedient next number
	return nums.size() + 1;
}

int main()
{
	vector<int> v {
		3, 1, -1, 1, 12, 5, 1, 1, 4, 1, 2, 0
	};

	cout << "firstMissingPositive linear extra space: " << firstMissingPositive_linearSpace(v) << '\n';
	cout << "firstMissingPositive inplace           : " << firstMissingPositive(v) << '\n';

	return 0;
}
