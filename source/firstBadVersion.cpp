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
inline void inspect(T& t){typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
You are a product manager and currently leading a team to develop a new 
product. Unfortunately, the latest version of your product fails the quality 
check. Since each version is developed based on the previous version, all the 
versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is 
bad. Implement a function to find the first bad version. You should minimize the 
number of calls to the API.
*/
const vector<int> versions {0,1};

bool isBadVersion(int version)
{
	return versions[version-1];
}

int firstBadVersion_helper(const int& nVersion, const int& b, const int& e)
{
	if(isBadVersion(1))
	{
		return 1;
	}

	if(b > e)
	{
		return -1;
	}

	int mid = (b+e)/2;

	if((not isBadVersion(mid-1)) and isBadVersion(mid))
	{
		return mid;
	}

	if(isBadVersion(mid))
	{
		return firstBadVersion_helper(nVersion, b, mid-1);
	}
	else
	{
		return firstBadVersion_helper(nVersion, mid+1, e);
	}
}

int firstBadVersion(const int& nVersion)
{

	return firstBadVersion_helper(nVersion, 1, nVersion);
}

int main()
{
	int nVersion = versions.size();
	cout << "first bad version at: " << firstBadVersion(nVersion) << '\n';

	return 0;
}
