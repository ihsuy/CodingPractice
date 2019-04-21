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
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

long long sq(const int& n)
{
	return n * n;
}

bool isHappy(int n)
{	// as stated in the problem,
	// in the process of suming up the
	// squares of digits, we either encounter a cycle
	// or encounter the number 1
	// so we need to proceed until one of these is true

	// hashset will be good to track every seen numbers
	// and if same number appeared again, we found a cycle
	unordered_set<int> cycle;

	for (int res = 0;;res = 0)
	{	
		do
		{	// calculate the sum of squares of digits
			res += sq(n % 10);
		} 
		while(n/=10);

		// found 1?
		if (res == 1)
		{	
			return true;
		}

		// found cycle?
		if (cycle.count(res))
		{	
			return false;
		}

		// continue...
		cycle.insert(res);
		n = res;
	}

	// undefined result
	return false;
}

int main()
{
	for(int i = 0; i < 1000; ++i)
	{
		cout << "number " << i << (isHappy(i)?" is happy": " is not happy") << '\n';
	}

	return 0;
}
