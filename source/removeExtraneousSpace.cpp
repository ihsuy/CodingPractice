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
remove all extraneous spaces and only leave one
*/

void removeExtranousSpace(string& s)
{
	if (s.length() == 0)
	{
		return;
	}

	bool beginWithSpace = (s[0] == ' ') ? true : false;
	bool endWithSpace = (s.back() == ' ') ? true : false;

	stringstream washer(s);
	string token;
	string result;
	result.reserve(s.length() + 1);

	while (washer >> token)
	{
		result += token + ' ';
	}

	if (result.length() == 0)
	{
		s = " ";
		return;
	}

	if (not endWithSpace)
	{
		result.pop_back();
	}

	if (beginWithSpace)
	{
		result.insert(0, " ");
	}

	s = result;
}


int main()
{
	string s = "ab";
	removeExtranousSpace(s);
	cout << "(" << s << ")" << '\n';

	return 0;
}