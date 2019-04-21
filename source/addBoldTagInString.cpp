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
{	// match word and slide window if longer word is found
	char initial_letter = s[left];

	int width = (right >= left) ? right - left : 0;

	bool updated = false;

	for (int i = 0; i < dict.size(); ++i)
	{
		string word = dict[i];

		if (word[0] == initial_letter and word.length() > width)
		{	// if word length is shorter than width, the word included
			// in a larger word, so we can ignore it
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

string addBoldTag(string s, vector<string>& dict)
{
	vector<pair<int, int>> result;

	for (int i = 0, j = 0; i < s.length(); ++i)
	{	// try to match word by word
		if (matchMove(i, j, s, dict))
		{
			if (result.empty())
			{
				result.push_back({i, j});
			}
			else
			{	// merge ranges
				if (i >= result.back().first and i <= result.back().second
				        and j > result.back().second)
				{
					auto temp = result.back();
					result.pop_back();
					result.push_back({temp.first, j});
				}
				else
				{
					result.push_back({i, j});
				}
			}
		}
	}

	if (result.size() == 0)
	{	// no match found
		return s;
	}

	vector<string> pieces;

	int prev_end = 0;

	for (int i = 0; i < result.size(); ++i)
	{	// seperate string into pieces and add tags
		string p1 = s.substr(prev_end, result[i].first - prev_end);
		string p2 = s.substr(result[i].first, result[i].second - result[i].first);
		if (p1.length() != 0)
		{
			pieces.push_back(p1);
		}
		pieces.push_back("<b>");
		pieces.push_back(p2);
		pieces.push_back("</b>");
		prev_end = result[i].second;
	}

	string p3 = s.substr(result.back().second, s.length() - result.back().second);
	if (p3.length() != 0)
	{
		pieces.push_back(p3);
	}

	string outcome;
	for (const auto& piece : pieces)
	{
		outcome += piece;
	}

	return outcome;

}

int main()
{
	string s = "aaabbbcc";
	vector<string> d {"aaa", "aab", "c", "bc"};

	string s2 = "abcxyz123";
	vector<string> d2{"abc", "123"};

	cout << "test 1 result: " << addBoldTag(s, d) << endl;
	cout << "test 2 result: " << addBoldTag(s2, d2) << endl;
	return 0;
}
