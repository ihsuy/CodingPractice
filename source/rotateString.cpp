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
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<typename T>
inline void inspect(typename T::iterator i1, typename T::iterator i2) {while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

bool rotateString(string A, string B) 
{
	if(A == B)
	{
		return true;
	}
	
	int alen = A.length(), blen = B.length();
	if(alen != blen)
	{
		return false;
	} 

	string C = A+A;
	int j, k;
	for(int i = 0; i < A.length(); ++i)
	{	
		if(C[i] == B[0])
		{
			j = 1;
			k = i+1;
			while(C[k] == B[j] 
				and (k < C.length() and j < B.length()))
			{
				k++;
				j++;
			}

			if(j == B.length())
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	cout << rotateString("abcde", "eabcd") << endl;

	return 0;
}
