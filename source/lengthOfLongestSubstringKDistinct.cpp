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

int lengthOfLongestSubstringKDistinct(const string& s, int k)
{
	if (s.length() == 0)
	{
		return 0;
	}
	unordered_set<char> unique_char;
	vector<int> changePoints;
	vector<int> unique_count;

	for (int i = 0; i < s.length(); ++i)
	{
		char ch = s[i];
		
		if (unique_char.count(ch) == 0)
		{
			cout << "i: " << i << '\n';
			changePoints.push_back(i);
			unique_char.insert(ch);
		}
		unique_count.push_back(unique_char.size());
	}

	changePoints.push_back(s.length());

	if (k > unique_char.size())
	{
		k = unique_char.size();
	}

	inspect<vector<int>>(changePoints);
	inspect<vector<int>>(unique_count);

	int result = 0;
	for (int i = 0, j = k; i < changePoints.size() - k; ++i, ++j)
	{
		int diff = changePoints[j] - changePoints[i];
		if (diff > result)
		{
			result = diff;
		}
	}
	return result;
}

int main()
{
	string s = "aba";
	int k = 1 ;

	cout << lengthOfLongestSubstringKDistinct(s, k) << '\n';

	return 0;
}
