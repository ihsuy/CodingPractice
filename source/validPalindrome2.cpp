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
Given a non-empty string s, 
you may delete at most one character. 
Judge whether you can make it a palindrome.
*/

bool isPalindrome(const string& s)
{
	int begin = 0, end = s.length() - 1;
	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

bool validPalindrome(const string& s)
{
	if (s.length() == 1)
	{
		return true;
	}

	int begin = 0, end = s.length() - 1;
	int missCounter = 0;
	while (begin < end)
	{
		if (s[begin] != s[end])
		{
			missCounter++;
			if (s[begin] == s[end - 1] and s[begin + 1] == s[end])
			{
				return isPalindrome(s.substr(0, end) + s.substr(end + 1)) or isPalindrome(s.substr(0, begin) + s.substr(begin + 1));
			}
			else if (s[begin] == s[end - 1])
			{
				end--;
			}
			else if (s[begin + 1] == s[end])
			{
				begin++;
			}
			else
			{
				return false;
			}
		}
		begin++;
		end--;
	}
	return (missCounter < 2);
}

int main()
{
	cout << validPalindrome("aba") << endl;
	cout << validPalindrome("abca") << endl;
	return 0;
}
