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
Given a stream of integers and a window size,
calculate the moving average of all integers in the sliding window.
*/

class MovingAverage {
public:

	/** Initialize your data structure here. */
	int window_size;
	list<double> window;
	double runningSum;
	MovingAverage(int size) : window_size(size), runningSum(0) {}

	double next(int val) {
		if (window.size() == window_size)
		{
			runningSum -= window.front();
			window.pop_front();
		}
		runningSum += val;
		window.push_back(val);

		return runningSum / window.size();
	}
};


int main()
{
	// MovingAverage m = new MovingAverage(3);
	// m.next(1) = 1
	// m.next(10) = (1 + 10) / 2
	// m.next(3) = (1 + 10 + 3) / 3
	// m.next(5) = (10 + 3 + 5) / 3

	return 0;
}
