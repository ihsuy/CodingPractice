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
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
*/

int missingNumber(vector<int>& nums)
{
	bool* arr = new bool[nums.size() + 1];
	memset(arr, false, sizeof(bool) * (nums.size() + 1));
	for (auto& n : nums)
	{
		arr[n] = true;
	}
	for (int i = 0; i < nums.size() + 1; ++i)
	{
		if (!arr[i])
		{
			return i;
		}
	}
	return -1;
}

int missingNumber_bitmanip(vector<int>& nums)
{	// an interesting solution
	// First notice: XOR is its own inverse
	// also, XOR is associative and commutative
	// if a full range of unique elements XOR with itself
	// will all cancel out
	// what happens if one number is missing?
	int final = nums.size();
	for (int i = 0; i < nums.size(); ++i)
	{
		final ^= (i ^ nums[i]);
	}
	return final;
}

int main()
{
	vector<int> nums {9, 6, 4, 2, 3, 5, 7, 0, 1};
	cout << missingNumber(nums) << '\n';
	cout << missingNumber_bitmanip(nums) << '\n';
	return 0;
}
