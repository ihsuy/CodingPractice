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
Given an array of characters, compress it in-place.
The length after compression must always be smaller than or equal to the original array.
Every element of the array should be a character (not int) of length 1.
After you are done modifying the input array in-place, return the new length of the array.
*/

int encode(int n, vector<char>& s, const int& i, int& j)
{	// works for n larger than 0
	// calculate number of digits in n
	// encode number in s

	// put the head of consecutive letters in its correct position
	s[j - 1] = s[i - 1];

	if (n == 1)
	{	// when n is 1 don't encode its length
		j ++;
		return 0;
	}

	// get length
	int result = 0;
	for (int temp = n; temp; temp /= 10)
	{
		result++;
	}

	// encode length
	string sn = to_string(n);
	for (int k = j; (n >= 2) and k < j + result; ++k)
	{
		s[k] = sn[k - j];
	}

	j += result + 1;
	return result;
}

int compress(vector<char>& s)
{
	if (s.size() == 0)
	{
		return 0;
	}

	int prev = 0;
	int i = 1 , j = 1;
	for (; i < s.size() + 1; ++i)
	{
		if (i == s.size() or s[i] != s[prev])
		{	// number of duplicates
			int count = i - prev;
			// encode
			encode(count, s, i, j);

			prev = i;
		}
	}
	// only keep the encoded portion of s
	s.erase(s.begin() + j - 1, s.end());

	return j - 1;
}

int compress_concise(vector<char>& chars) {
	const int n = chars.size();

	int p = 0;

	for (int i = 1; i <= n; ++i)
	{
		int count = 1;

		while (i < n && chars[i] == chars[i - 1])
		{
			++i;
			++count;
		}

		chars[p++] = chars[i - 1];

		if (count == 1)
		{
			continue;
		}

		for (char c : to_string(count))
		{
			chars[p++] = c;
		}
	}

	return p;
}

int main()
{
	vector<char> v {'a', 'a', 'a', 'b', 'b', 'a', 'x', 'a', 'a', 'a', 'a', 'b', 'a', 'a', 'a'};
	cout << "compressed length: " << compress(v) << '\n';
	inspect<vector<char>>(v);
	return 0;
}
