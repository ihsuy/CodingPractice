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

void increment_counter(int& unique_count, vector<int>& letter_count, const char& n)
{	
	if (letter_count[n] == 0)
	{	// never seen this letter, so its unique
		unique_count++;
		letter_count[n]++;
	}
	else
	{
		letter_count[n]++;
	}
}

void decrement_counter(int& unique_count, vector<int>& letter_count, const char& n)
{	// decrement counter, decrement unique_count if its counter becomes 0
	letter_count[n]--;

	if (letter_count[n] <= 0)
	{
		unique_count--;
	}
}

int lengthOfLongestSubstringKDistinct(const string& s, int k)
{
	if (s.length() == 0 or k == 0)
	{
		return 0;
	}

	int result = 1;

	// possible 128 characters in inputs
	vector<int> letter_count(128, 0);
	int unique_count = 0;

	// probing s using window (i, j)
	int i = 0, j = 0;

	for (; j < s.length();)
	{	// loop ends when rhs of the window exceeds array boundary
		if (unique_count != k or letter_count[s[j]] != 0)
		{	// if the substring contain less than k character 
			// or its not going to contain more than k characters
			// move rhs of the window to right, until this condition doesn't hold
			increment_counter(unique_count, letter_count, s[j]);
			j++;
		}
		else
		{	// if the current substring already contain k unique characters
			// and we've discovered another new unique character 
			// to not exceed k, we can't proceed further.
			// update result
			result = max(j - i, result);

			while (unique_count == k)
			{	// move lhs of window to the right,
				// until current substring contains less than k element
				decrement_counter(unique_count, letter_count, s[i]);
				i++;
			}
		}
	}

	// since the case when j == s.length() isn't handled yet
	// we do it here
	return max(j - i, result);;
}

int main()
{
	string s = "ecebebeee";
	int k = 2 ;

	cout << lengthOfLongestSubstringKDistinct(s, k) << '\n';

	return 0;
}
