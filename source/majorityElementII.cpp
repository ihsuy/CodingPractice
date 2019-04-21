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

vector<int> majorityElement(vector<int>& nums)
{	// since we are look for elements that appear more than n/3 times
	// we immediently know, there're at most 2 different candidates
	// Otherwise, 3 distinct elements are in the same array and
	// all have appeared more than n/3 element would imply the array contains
	// more than n elemenst which is a contradiction

	// prepare 2 slots for candidates
	int n1, n2;
	// prepare 2 counters
	int h1 = 0, h2 = 0;

	// our goal is to find the 2 most appearing elements in nums
	// in linear time and only using constant space

	for (int i = 0; i < nums.size(); ++i)
	{	// this approach can be understood by imagining a bar graph where the
		// height of bars indicating the relative quantity of each element
		// in the vector. We only keep 2 bars on the graphs indicating the
		// 2 elements of interests. Another appearance of elements already on
		// the graph will increase its height, whereas a brand new element will
		// decrease heights for both bars since that would mean the quantities
		// of our two candidate elements are becoming less dominating
		int curr = nums[i];

		if (h1 == 0 and h2 == 0)
		{	// both bars have height equal to 0 implies all elements we've
			// seen so far had an even distribution in terms of their quantities
			// any new elements found after this point, will become the most dominating
			// one and will be inserted in n1's slot
			n1 = curr;
			h1++;
		}
		else if (h1 != 0 and h2 == 0)
		{	// since the second slot is open, insert it there
			if (curr == n1)
			{
				h1++;
			}
			else
			{
				n2 = curr;
				h2++;
			}
		}
		else if (h1 == 0 and h2 != 0)
		{
			if (curr == n2)
			{
				h1++;
			}
			else
			{
				n1 = curr;
				h1++;
			}
		}
		else if (h1 != 0 and h2 != 0)
		{
			if (curr == n1)
			{
				h1++;
			}
			else if (curr == n2)
			{
				h2++;
			}
			else
			{
				h1--;
				h2--;
			}
		}
	}

	// now we've obtained the 2 most dominating elements
	// in terms of quantities, we then check if their quantities
	// actually exceed n/3
	vector<int> result;
	int oneThrid = nums.size() / 3;

	h1 = h2 = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] == n1)
		{
			h1++;
		}
		else if (nums[i] == n2)
		{
			h2++;
		}
	}
	if (h1 > oneThrid)
	{
		result.push_back(n1);
	}
	if (h2 > oneThrid)
	{
		result.push_back(n2);
	}
	return result;
}

int main()
{
	vector<int> v = {1, 3, 1, 8, 7, 3, 3, 6, 1, 3, 1};
	auto result = majorityElement(v);
	for (auto& item : result)
	{
		cout << item << " ";
	}
	cout << '\n';
	return 0;
}
