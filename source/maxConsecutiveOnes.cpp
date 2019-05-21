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
Given a binary array, find the maximum number of consecutive 1s in this array.
*/

int findMaxConsecutiveOnes(const vector<int>& nums)
{
	int result = 0;
	int prev_zeroCount = 0;
	int current_zeroCount = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 1)
		{
			current_zeroCount++;
		}
		else
		{
			result = max(result, prev_zeroCount + current_zeroCount);
			if (i == 0 or i == nums.size() - 1)
			{
				prev_zeroCount = 1;
			}
			else
			{
				if (nums[i - 1] == 1 and nums[i + 1] == 1)
				{
					prev_zeroCount = current_zeroCount + 1;
					current_zeroCount = 0;
				}
				else if (nums[i - 1] == 1)
				{
					result = max(result, current_zeroCount + 1);
					prev_zeroCount = 0;
					current_zeroCount = 0;
				}
				else if (nums[i + 1] == 1)
				{
					prev_zeroCount = 1;
				}
				else
				{
					result = max(result, 1);
				}
			}
		}
	}
	result = max(result, prev_zeroCount + current_zeroCount);
	return result;
}

int findMaxConsecutiveOnes2(vector<int>& nums) 
{
	nums.push_back(0);
	int len = nums.size(), result = 0;
	for (int i = 0, count = 0; i < len; ++i)
	{
		if (nums[i] == 1)
		{
			count ++;
		}
		else
		{
			if (count > result)
			{
				result = count;
			}
			count = 0;
		}
	}
	return result;
}

int main()
{
	vector<int> v {1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1};
	cout << findMaxConsecutiveOnes(v) << endl;

	return 0;
}

