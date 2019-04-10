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
Given an array of integers nums, write a method that returns 
the "pivot" index of this array.

We define the pivot index as the index where the sum 
of the numbers to the left of the index is equal to the 
sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there 
are multiple pivot indexes, you should return the 
left-most pivot index.
*/

int pivotIndex(vector<int>& nums)
{

	if (nums.size() == 0)
	{
		return -1;
	}

	int leftSum = 0, rightSum = accumulate(nums.begin() + 1, nums.end(), 0);

	if (leftSum == rightSum)
	{
		return 0;
	}

	for (int i = 1; i < nums.size(); ++i)
	{
		leftSum += nums[i - 1];
		rightSum -= nums[i];

		if (leftSum == rightSum)
		{
			return i;
		}
	}

	return -1;
}

int main()
{


	return 0;
}
