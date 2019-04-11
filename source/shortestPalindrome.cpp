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
Given a string s, you are allowed to convert it to a palindrome
by adding characters in front of it. Find and return the shortest
palindrome you can find by performing this transformation.
*/

string shortestPalindrome1(string s)
{	// slow
	int front = 0, back = s.length() - 1;
	int prev_back = back;
	while (front < back)
	{
		if (s[front] == s[back])
		{
			front++;
			back--;
		}
		else
		{
			front = 0;
			back = prev_back - 1;
			prev_back = back;
		}
	}

	int len = 0;
	if (front == back)
	{
		len = front * 2 + 1;
	}
	else
	{
		len = front * 2;
	}

	string prefix = s.substr(len);
	reverse(prefix.begin(), prefix.end());
	return prefix + s;
}

string shortestPalindrome2(string s)
{	// a bit faster
	string rev_s(s);
	reverse(rev_s.begin(), rev_s.end());

	int i = 0;
	for(; i < s.length(); ++i)
	{
		if(s.compare(0, s.length()-i, rev_s, i, s.length()-i) == 0)
		{
			break;
		}
	}

	return rev_s.substr(0, i)+s;
}

int main()
{
	string s = "aaaaaaaba";
	cout << shortestPalindrome1(s) << '\n';
	cout << shortestPalindrome2(s) << '\n';

	return 0;
}
