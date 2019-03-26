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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<typename T>
inline void inspect(T t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Write a function that reverses a string. The input string is given as an array 
of characters char[].

Do not allocate extra space for another array, you must do this by modifying
the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.
*/

void reverseString(vector<char>& s) 
{
	int len = s.size();
	if(len == 0)
	{
		return;
	}

	// swap the first half with the second half
	char temp = 0;

	for(int i = 0; i < len/2; ++i)
	{
		temp = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = temp;
	}
}

int main()
{
	string s = "abcdefghijklmnopqrstuvwxyz";
	vector<char> sv(s.begin(), s.end());
	reverseString(sv);

	inspect<vector<char>>(sv);

	return 0;
}