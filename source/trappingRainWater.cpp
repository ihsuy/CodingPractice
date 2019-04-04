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

vector<int>::iterator lfind_FirstNoneZero(vector<int>& v)
{
	auto ite = v.begin();
	while(ite != v.end())
	{
		if(*ite != 0)
		{
			return ite;
		}
		ite++;
	}
	return ite;
}

vector<int>::iterator rfind_FirstNoneZero(vector<int>& v)
{
	auto ite = v.end()-1;
	while(ite != v.begin())
	{
		if(*ite != 0)
		{
			return ite;
		}
		ite--;
	}
	return ite;
}

void trimSides(vector<int>& h)
{
	auto left = lfind_FirstNoneZero(h);

	if(h.size() != 0 and left == h.end())
	{
		h.clear();
		return;
	}

	auto right = rfind_FirstNoneZero(h)+1;

	h = vector<int>(left, right);

}

void decrement_noneZero(int& val)
{
	if(val!=0)
	{
		val--;
	}
}

int trap_simulation(vector<int> height) 
{
	if(height.size() == 0)
	{
		return 0;
	}

	trimSides(height);

	int result = 0;
	
	while(height.size() != 0)
	{
		inspect<vector<int>>(height);

		result += count(height.begin(), height.end(), 0);

		for_each(height.begin(), height.end(), decrement_noneZero);

		trimSides(height);
	}

	return result;
}

int main()
{
	// vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> v{0,0,0};

	cout << trap_simulation(v) << '\n';
	//for_each(v.begin(), v.end(), decrement_noneZero);

	//inspect<vector<int>>(v);
	return 0;
}
