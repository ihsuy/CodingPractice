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
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
*/

class PhoneDirectory {
public:
	int maxNum;
	unordered_set<int> numberTaken;

	PhoneDirectory(int maxNumbers) : maxNum(maxNumbers) {}

	int get() {
		if (numberTaken.size() == maxNum)
		{
			return -1;
		}
		for (int i = 0; i < maxNum; ++i)
		{
			if (numberTaken.count(i) == 0)
			{
				numberTaken.insert(i);
				return i;
			}
		}
		return -1;
	}

	/** Check if a number is available or not. */
	bool check(int number) {
		if (number >= maxNum)
		{
			return false;
		}
		return (numberTaken.count(number) == 0);
	}

	/** Recycle or release a number. */
	void release(int number) {
		if (number >= maxNum)
		{
			throw runtime_error("Can't not release a number that's larger than the maximum number.");
		}

		if (numberTaken.count(number) != 0)
		{
			numberTaken.erase(number);
		}
	}
};


/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */

int main()
{


	return 0;
}
