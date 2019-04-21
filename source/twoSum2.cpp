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
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/

vector<int> twoSum(vector<int>& numbers, int target) 
{	// goal: find indices for 2 different 
	// numbers in array that sum up to the target
	// addiontal information: the array is sorted
	// have a sorted array as our input makes this 
	// problem alot simpler, since we already "know" where 
	// each elements are, i.e. if the number we are looking at is too big
	// we can just move to the left to find a smaller one and vise versa
	int left = 0, right = numbers.size() - 1;

	while (left < right)
	{	
		int temp = numbers[left] + numbers[right];
		if (temp == target)
		{
			return {left + 1, right + 1};
		}

		if (temp < target)
		{	// too small: move right to get a larger candidate
			left++;
		}
		else
		{	// too big...
			right--;
		}
	}
	// indicate not found
	return {-1, -1};
}

int main()
{
	vector<int> numbers {2,7,11,15};
	int target = 9;
	auto result = twoSum(numbers, target);
	inspect<vector<int>>(result);

	return 0;
}
