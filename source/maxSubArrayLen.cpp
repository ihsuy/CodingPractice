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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(typename T::iterator i1, typename T::iterator i2) {while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

int maxSubArrayLen(vector<int>& nums, int k)
{
	unordered_map<int, int> buffer;

	int result = INT_MIN;

	int runningSum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		runningSum += nums[i];

		int val = nums[i] - runningSum;
		if (buffer.find(val) == buffer.end())
		{
			buffer[val] = i;
		}

		int target = k - runningSum;
		if (buffer.find(target) != buffer.end())
		{
			int dis = i - buffer[target] + 1;
			if (dis > result)
			{
				result = dis;
			}
		}
	}

	return (result == INT_MIN ? 0 : result);
}

int main()
{


	return 0;
}
