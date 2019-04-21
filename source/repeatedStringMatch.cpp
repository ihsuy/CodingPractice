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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(typename T::iterator i1, typename T::iterator i2) {while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

int repeatedStringMatch(const string& A, const string& B)
{
	int alen = A.length(), blen = B.length();

	// find the first appearance of substring of B in A
	int result = 0;

	int ai = 0, bi = 0;
	int temp_ai = 0;

	while (ai != alen and bi != blen)
	{
		ai = temp_ai;
		bi = 0;

		while (ai < alen and A[ai] != B[bi])
		{
			ai++;
		}
		// if this reaches at the end of ai, then B[0] is not contained in A
		if (ai == alen)
		{
			return -1;
		}

		temp_ai = ai + 1;

		// else check if this is the correct starting point
		while (ai != temp_ai - 2
		        and bi < blen and A[ai] == B[bi])
		{	// wrap searching in A
			ai = (ai + 1) % alen;
			bi++;

			if (temp_ai - 2 < 0 and ai == 0)
			{	// handle loop breaking corner case
				// when starting point and end point
				// has to be the same point
				break;
			}
		}

		if (A[ai] == B[bi])
		{	// we found a good starting point
			break;
		}
	}

	ai = temp_ai - 1;
	bi = 0;

	if (ai != 0)
	{	// a piece of A detected in the beginning of B
		// repeat once
		result ++;
	}

	// from now on, loop A and B using ai bi simulaneously
	// everytime ai hits A[0], result ++
	while (bi != blen)
	{
		if (A[ai] != B[bi])
		{
			return -1;
		}

		if (ai == 0)
		{
			result ++;
		}

		ai = (ai + 1) % alen;
		bi++;
	}

	return result;
}

int main()
{
	cout << repeatedStringMatch("a", "aa") << endl;

	return 0;
}
