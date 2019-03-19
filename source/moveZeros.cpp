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
Given an array nums, write a function to move all 0's to the end 
of it while maintaining the relative order of the non-zero elements.
*/

void moveZeroes(vector<int>& nums) 
{
	for(int i = 0, j = 0; i < nums.size(); ++i)
	{
		if(nums[i] == 0 and nums[j] != 0)
		{
			j = i;
		}
		else if(nums[i] != 0)
		{
			int temp = nums[i];
			nums[i] = 0;
			nums[j] = temp;
			j++;
		}
	}
}

int main()
{
	vector<int> v {1,2,0,4,0,2,1,4,0,0,0,9};
	moveZeroes(v);

	inspect<vector<int>>(v);

	return 0;
}
