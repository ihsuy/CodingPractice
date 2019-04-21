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

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> result;
	result.reserve(m + n);

	int i = 0, j = 0;
	while ((i < m) and (j < n))
	{
		if (nums1[i] <= nums2[j])
		{
			result.push_back(nums1[i]);
			i++;
		}
		else
		{
			result.push_back(nums2[j]);
			j++;
		}
	}
	if (i == m)
	{
		result.insert(result.end(), nums2.begin() + j, nums2.end());
	}
	else
	{
		result.insert(result.end(), nums1.begin() + i, nums1.begin() + m);
	}

	nums1 = result;
}

int main()
{
	vector<int> v1 = {2, 0};
	vector<int> v2 = {1};

	merge(v1, 1, v2, 1);

	inspect<vector<int>>(v1.begin(), v1.end());

	return 0;
}
