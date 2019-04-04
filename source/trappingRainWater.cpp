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
Given n non-negative integers representing an elevation map where the width
of each bar is 1, compute how much water it is able to trap after raining.
*/

// pair<vector<int>::iterator, vector<int>::iterator> trimSides(vector<int>::iterator front, vector<int>::iterator back)
// {
// 	vector<int>::iterator low = front, high = back;

// 	bool foundLow = false, foundHigh = false;
// 	while (front != back and (not foundLow or not foundHigh))
// 	{
// 		if (not foundLow)
// 		{
// 			if (*front != 0)
// 			{
// 				low = front;
// 				foundLow = true;
// 			}
// 			front++;
// 		}

// 		if (not foundHigh)
// 		{
// 			if(*back != 0)
// 			{
// 				high = back;
// 				foundHigh = true;
// 			}
// 			back--;
// 		}

// 	}
// 	if(front == back)
// 	{
// 		return {front, back};
// 	}
// 	return {low, high};
// }


// int min_nonZeroElement(vector<int>::iterator begin, vector<int>::iterator end)
// {
// 	int min_ele = INT_MAX;
// 	for (; begin != end+1; ++begin)
// 	{

// 		if (*begin != 0 and * begin < min_ele)
// 		{
// 			min_ele = *begin;
// 		}
// 	}
// 	return (min_ele == INT_MAX) ? 0 : min_ele;
// }

// int fillWater(vector<int>::iterator begin, vector<int>::iterator end)
// {

// 	int decrease_amount = min_nonZeroElement(begin, end);

// 	int zero_counter = 0;

// 	for (; begin != end+1; ++begin)
// 	{
// 		if (*begin == 0)
// 		{
// 			zero_counter++;
// 		}
// 		else
// 		{
// 			(*begin) -= decrease_amount;
// 		}
// 	}

// 	return zero_counter * decrease_amount;
// }

// int trap_simulation(vector<int> height)
// {	// calculate the result by actually simulate the filling process
// 	// this is a n^2 algorithm
// 	if (height.size() == 0)
// 	{
// 		return 0;
// 	}

// 	auto p = trimSides(height.begin(), height.end()-1);

// 	int result = 0;

// 	while (p.first != p.second)
// 	{	// visualize how the heights are filled
// 		inspect<vector<int>>(height);

// 		result += fillWater(p.first, p.second);

// 		p = trimSides(p.first, p.second);
// 	}

// 	return result;
// }

// <<<<<<<<<<< Solutions <<<<<<<<<<<
// brute force

int trap_bf(const vector<int>& height)
{	// find exactly how many water can a position trap.
	// Iterate over the vector, then for every position
	// find the highest position on the left and right of it
	// respectively. take the smaller one and substract current height
	int result = 0;
	for (auto ite = height.begin() + 1; ite != height.end() - 1; ++ite)
	{
		int leftMax = *max_element(height.begin(), ite);
		int rightMax = *max_element(ite + 1, height.end());

		int h = ((leftMax > rightMax) ? rightMax : leftMax) - *ite ;

		if (h > 0)
		{
			result += h;
		}
	}

	return result;
}

int trap_bf_improved(const vector<int>& height)
{	// find exactly how many water can a position trap.
	// Iterate over the vector, then for every position
	// find the highest position on the left and right of it
	// respectively. take the smaller one and substract current height
	if (height.size() < 3)
	{
		return 0;
	}

	int result = 0;

	int leftMax = height[0];
	int rightMax = *max_element(height.begin() + 2, height.end());

	for (auto ite = height.begin() + 1; ite != height.end() - 1; ++ite)
	{
		int c = 0;
		if (*ite == rightMax)
		{
			rightMax = *max_element(ite + 1, height.end());
			c++;
		}

		if (*ite > leftMax)
		{
			leftMax = *ite;
			c++;
		}

		if (c)
		{
			continue;
		}

		int h = ((leftMax > rightMax) ? rightMax : leftMax) - *ite ;
		if (h > 0)
		{
			result += h;
		}
	}

	return result;
}

int trap_memo(const vector<int>& height)
{	// pre-calculate and memorize leftmax and rightmax
	// then use the stored information to do the job
	// just like the previous methods, however this runs in O(n)
	vector<pair<int, int>> lr_max(height.size(), pair<int, int>(0,0));

	int len = height.size();

	int leftMax = 0, rightMax = 0;

	for(int i = 0, j = len-1; i < len; ++i, --j)
	{
		if(height[i] > leftMax)
		{
			leftMax = height[i];
		}
		if(height[j] > rightMax)
		{
			rightMax = height[j];
		}
		lr_max[i].first = leftMax;
		lr_max[j].second = rightMax;
	}
	
	int result = 0;

	for(int i = 0; i < len; ++i)
	{
		int h = min(lr_max[i].first,lr_max[i].second)-height[i];
		if(h>0)
		{
			result += h;
		}
	}

	return result;
}

int main()
{
	vector<int> v2{10527, 740, 9013, 1300, 29680, 4898, 13993, 15213, 18182, 24254, 3966, 24378, 11522, 9190};
	vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	cout << "brute force result: " << trap_bf(v2) << '\n';

	cout << "brute force - improved result: " << trap_bf_improved(v2) << '\n';

	cout << "memo result: " << trap_memo(v2) << '\n';

	return 0;
}
