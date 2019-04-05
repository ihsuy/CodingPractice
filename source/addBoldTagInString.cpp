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
Given a string s and a list of strings dict, you need
to add a closed pair of bold tag <b> and </b> to wrap the
substrings in s that exist in dict. If two such substrings
overlap, you need to wrap them together by only one pair of
closed bold tag. Also, if two substrings wrapped by bold tags
are consecutive, you need to combine them.
*/

bool matchMove(int& left, int& right, const string& s, vector<string>& dict)
{
	char initial_letter = s[left];
	int width = (right >= left) ? right - left : 0;

	bool updated = false;

	for (int i = 0; i < dict.size(); ++i)
	{
		string word = dict[i];

		if (word[0] == initial_letter and word.length() > width)
		{
			int j = 1;
			for (; j < word.length(); ++j)
			{
				if (s[left + j] != word[j])
				{
					break;
				}
			}
			if (j == word.length())
			{
				right = left + j;
				width = right - left;
				updated = true;
			}
		}
	}

	return updated;
}

void mergeRanges(vector<pair<int, int>>& ranges)
{
	vector<pair<int, int>> result;
	for (int i = 1; i < ranges.size(); ++i)
	{
		if (ranges[i].first >= ranges[i - 1].first and ranges[i].first <= ranges[i - 1].second
		        and ranges[i].second > ranges[i - 1].second)
		{
			result.push_back({ranges[i - 1].first, ranges[i].second});
		}
		else
		{
			result.push_back(ranges[i-1]);
			if(i == ranges.size()-1)
			{
				result.push_back(ranges[i]);
			}
		}
	}
	ranges = result;
}

// string addBoldTag(string s, vector<string>& dict)
// {
// 	int left = 0, right = 0;
// }

int main()
{
	string s = "aaabbcc";
	vector<string> d {"aaa", "aab", "bc"};

	// string s = "abcxyz123";
	// vector<string> d{"abc", "123"};

	// int l = 4, r = 4;
	// matchMove(l, r, s, d);
	vector<pair<int, int>> ranges;
	for (int i = 0, j = 0; i < s.length(); ++i)
	{
		if (matchMove(i, j, s, d))
		{
			ranges.push_back({i, j});
		}
	}

	mergeRanges(ranges);

	for(auto item : ranges)
	{
		printf("(%d, %d)\n", item.first, item.second);
	}

	return 0;
}
