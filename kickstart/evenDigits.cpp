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
Supervin has a unique calculator. This calculator only has a display, a 
plus button, and a minus button. Currently, the integer N is displayed on the calculator display.

Pressing the plus button increases the current number displayed on the 
calculator display by 1. Similarly, pressing the minus button decreases the 
current number displayed on the calculator display by 1. The calculator does not display any 
leading zeros. For example, if 100 is displayed on the calculator display, pressing the minus 
button once will cause the calculator to display 99.

Supervin does not like odd digits, because he thinks they are "odd". 
Therefore, he wants to display an integer with only even digits in its decimal 
representation, using only the calculator buttons. Since the calculator is a bit old and the 
buttons are hard to press, he wants to use a minimal number of button presses.

Please help Supervin to determine the minimum number of button presses to make 
the calculator display an integer with no odd digits.

Input
The first line of the input gives the number of test cases, T. T test cases follow. 
Each begins with one line containing an integer N: the integer initially displayed 
on Supervin's calculator.

Output
For each test case, output one line containing Case #x: y, where x is the test case 
number (starting from 1) and y is the minimum number of button presses, as described above.

Limits
1 ≤ T ≤ 100.
Time limit: 20 seconds per test set.
Memory limit: 1GB.
*/



int main()
{
	int T = 0;
	cin >> T;
	while(T--)
	{
		int N;
		cin >> N;

		
	}

	return 0;
}
