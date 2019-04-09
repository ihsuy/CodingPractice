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
Given two strings S and T, return if they are equal when 
both are typed into empty text editors. # means a backspace character.
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
*/

bool backspaceCompare(const string& s, const string& t)
{
	string l1, l2;
	for (const char& ch : s)
	{
		if (not l1.empty() and ch == '#')
		{
			l1.pop_back();
		}
		else if (ch != '#')
		{
			l1.push_back(ch);
		}
	}
	for (const char& ch : t)
	{
		if (not l2.empty() and ch == '#')
		{
			l2.pop_back();
		}
		else if (ch != '#')
		{
			l2.push_back(ch);
		}
	}
	return l1 == l2;
}


int main()
{
	cout << backspaceCompare("a#b##cd", "###cc#c#d") << endl;
	cout << backspaceCompare("a#b##cd", "###ccc#c#d") << endl;
	return 0;
}
