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
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/


// this algorithm generates result by iterating through s once
// for the first k letter
// look for patterns for letters on the same row
// we observe that zigzaging is actually jumping up and down
// in a symmetric manner.
// i.e. for example, for k = 4 and s = "PAYPALISHIRING"
// the 0th letter is first appended to result
// and we jump down for (k-0-1)*2 steps
// then we jump up for 0*2, then jump down and so on
// until i is out of range
// for the 1th letter its the same we jump down (k-1-1)*2 and up for 1*2...
// after iterating throught the first k letters
// we already have the result.
string zigzagnize(const string& s, const int& k)
{
	if (k == 1)
	{	// if k is 1 then there's no zigzaging
		return s;
	}

	int slen = s.length();

	string result;
	result.reserve(slen);

	for (int p = 0; p < k; ++p)
	{	// iterate over first k letter
		for (int i = p, c = 0, step = 1; i < slen; i += step, c++)
		{	// c is a counter used to determine whether should i jump up or down
			if (step != 0)
			{	// if i jumps for 0 steps, ofc we don't appended the same letter again
				result += s[i];
			}
			// decide jump up or down
			step = (c % 2 == 0) ? ((k - p - 1) * 2) : (p * 2);
		}
	}

	return result;
}

int main()
{
	string s = "PAYPALISHIRING";
	cout << zigzagnize(s, 4) << '\n';

	return 0;
}
