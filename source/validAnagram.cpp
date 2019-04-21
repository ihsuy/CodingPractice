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
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
*/

bool isAnagram(string s, string t)
{
	if (s.length() != t.length())
	{	// can't be anagram if sizes are equal
		return false;
	}

	// use arr as a composition map
	int* arr = new int[27];
	memset(arr, 0, sizeof(int) * 27);

	for (auto& ch : s)
	{	// count occurance every character
		arr[ch - 'a'] ++;
	}

	for (auto& ch : t)
	{
		int c = ch - 'a';
		if (arr[c] == 0)
		{	// this means we've now seen a character
			// in t that wasn't in s
			return false;
		}
		// decrement counter after seeing the same character in t
		arr[c]--;
	}

	return true;
}

int main()
{
	const string s1 = "stable";
	const string s2 = "tables";
	const string s3 = "aaabb";
	const string s4 = "aabbb";
	printf("%s and %s are anagram? : %d\n", s1.c_str(), s2.c_str(), isAnagram(s1, s2));
	printf("%s and %s are anagram? : %d\n", s3.c_str(), s4.c_str(), isAnagram(s3, s4));
	return 0;
}
