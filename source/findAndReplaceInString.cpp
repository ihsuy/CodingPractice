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
To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.
*/

string findReplaceString(string S, vector<int> indexes, vector<string>& sources, vector<string>& targets)
{
	int offset = 0;

	vector<pair<int, pair<string, string>>> inputs;

	for (int i = 0; i < indexes.size(); ++i)
	{
		inputs.push_back({indexes[i], {sources[i], targets[i]}});
	}

	sort(inputs.begin(), inputs.end(), [](pair<int, pair<string, string>>& p1, pair<int, pair<string, string>>& p2) {return p1.first < p2.first;});

	for (int i = 0; i < inputs.size(); ++i)
	{
		bool validSource = true;
		int left = inputs[i].first + offset;
		int right = left + inputs[i].second.first.length();
		for (int j = left; j < right; ++j)
		{
			if (S[j] != inputs[i].second.first[j - left])
			{

				validSource = false;
				break;
			}
		}
		if (validSource)
		{
			S.replace(left, inputs[i].second.first.length(), inputs[i].second.second);
			offset += inputs[i].second.second.length() - inputs[i].second.first.length();
		}
	}

	return S;
}

string findReplaceString2(string S, vector<int>& idx, vector<string>& src, vector<string>& tgs) 
{
	map<int, pair<int, string>, greater<int>> m;

	for (auto i = 0; i < idx.size(); ++i)
	{
		if (S.find(src[i], idx[i]) == idx[i])
		{
			m[idx[i]] = { src[i].size(), tgs[i] };
		}
	}

	for (auto& r : m)
	{
		S.replace(r.first, r.second.first, r.second.second);
	}

	return S;
}


int main()
{
	const string s = "abcd";
	const vector<int> indexes{0, 2};
	vector<string> sources {"a", "cd"};
	vector<string> targets {"eee", "ffff"};

	cout << findReplaceString(s, indexes, sources, targets) << endl;

	return 0;
}
