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
	int oneCounter = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == 1)
		{
			oneCounter++;
		}
		else
		{
			if (oneCounter > result)
			{
				result = oneCounter;
			}

			if (i >= nums.size() - result - 1)
			{
				break;
			}

			oneCounter = 0;
		}
	}

	if (oneCounter > result)
	{
		return oneCounter;
	}

	return result;
}

int main()
{
	vector<int> v {1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1};
	cout << findMaxConsecutiveOnes(v) << endl;

	return 0;
}
