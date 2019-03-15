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

string longestPalindrome(string s)
{
	int win_max = s.length();
	int win_min = 2;
	while (win_max >= win_min)
	{
		for (int i = 0; i <= s.length() - win_max; ++i)
		{
			int b = i;
			int e = i+win_max-1;

			while(b < e)
			{
				if(s[b] != s[e])
				{
					break;
				}
				b++;
				e--;
			}
			if(b >= e)
			{
				return s.substr(i, win_max);
			}
		}
		win_max--;
	}
	return string(1,s[0]);
}

int main()
{
	cout << longestPalindrome("cbbd") << endl;

	return 0;
}
