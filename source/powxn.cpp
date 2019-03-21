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
Implement pow(x, n), which calculates x raised to the power n (xn).
*/

double mypow_helper(const double& x, const int& n)
{
	if(n==0 or x==1)
	{
		return 1;
	}
	if(n==1)
	{
		return x;
	}
	double temp = mypow_helper(x, n/2);
	if(n%2 == 0)
	{	
		return temp*temp;
	}
	else
	{
		return temp*temp*x;
	}
}
double mypow(const double& x, const int& n)
{
	if(n < 0)
	{
		return 1/mypow_helper(x, -n);
	}
	return mypow_helper(x, n);
}

int main()
{
	cout << mypow(-2123809, -20) << endl; 

	return 0;
}
