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
Longest Substring with At Most K Distinct Characters
Given a string, find the length of the longest substring
T that contains at most k distinct characters.
*/

void increment_counter(unordered_map<char, int>& unique_count, const char& n)
{	// safely increment counter
	// handle the default case : when int is uninitialized set to 1
	if (unique_count.count(n) == 0)
	{
		unique_count[n] = 1;
	}
	else
	{
		unique_count[n]++;
	}
}

void decrement_counter(unordered_map<char, int>& unique_count, const char& n)
{	// decrement counter, remove entry completely if its counter becomes 0
	unique_count[n]--;
	if (unique_count[n] <= 0)
	{
		unique_count.erase(n);
	}
}

int lengthOfLongestSubstringKDistinct(const string& s, int k)
{
	if (s.length() == 0 or k == 0)
	{	
		return 0;
	}

	int result = 1;

	unordered_map<char, int> unique_count;

	// probing s using window (i, j)
	int i = 0, j = 0;

	for (; j < s.length();)
	{	// loop ends when rhs of the window exceeds array boundary
		if (unique_count.size() != k or unique_count.count(s[j]) != 0)
		{	// if the substring doesn't contain more than k character
			// move rhs of the window to right, until this doesn't hold
			increment_counter(unique_count, s[j]);
			j++;
		}
		else
		{	// if the current substring already contain k unique characters
			// and we've discovered another new character
			// update result
			result = max(j-i, result);

			while (unique_count.size() == k)
			{	// move lhs of window to the right,
				// until current substring contains less than k element
				decrement_counter(unique_count, s[i]);
				i++;
			}
		}
	}
	
	// since the case when j == s.length() isn't handled yet
	// we do it here
	return max(j-i, result);;
}

int main()
{
	string s = "ecebebeee";
	int k = 2 ;

	cout << lengthOfLongestSubstringKDistinct(s, k) << '\n';

	return 0;
}
