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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<typename T>
inline void inspect(T& t){typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given two arrays, write a function to compute their intersection.
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{	// only use std functions

	// sort them so "set_intersection" can be performed
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	vector<int> result;
	result.reserve(nums1.size());

	// find intersections but this doesn't remove duplicates
	set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(result));

	// remove duplicates but doesn't resize
	auto it = unique(result.begin(), result.end());

	// resize it to obtain final result
	result.resize(distance(result.begin(), it));

	return result;
}

vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) 
{	// use unordered_set to remove duplicates

	unordered_set<int> uniq{nums1.begin(), nums1.end()};

	nums1.clear();

	for(int i = 0; i < nums2.size(); ++i)
	{
		auto temp = nums2[i];
		if(uniq.count(temp) != 0)
		{
			nums1.push_back(temp);
			uniq.erase(temp);
		}
	}
	return nums1;
}

int main()
{
	vector<int> v1{2,2,3,4,5,1,2,3,3};
	vector<int> v2{2,2,3,4,5,1,2,3,3};
	auto result = intersection(v1, v2);
	inspect<vector<int>>(result);
	auto result2 = intersection2(v1, v2);
	inspect<vector<int>>(result2);
	return 0;
}
