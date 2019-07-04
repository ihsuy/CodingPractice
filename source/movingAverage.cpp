#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/


class MovingAverage {
   public:
    /** Initialize your data structure here. */
    int window_size;
    list<double> window;
    double runningSum;
    MovingAverage(int size) : window_size(size), runningSum(0) {}

    double next(int val) {
        if (window.size() == window_size) {
            runningSum -= window.front();
            window.pop_front();
        }
        runningSum += val;
        window.push_back(val);

        return runningSum / window.size();
    }
};
class MovingAverage2 {
	queue<int> window;
	const int winSize;
	int rs = 0;
public:
    /** Initialize your data structure here. */
    
    MovingAverage2(const int& windowSize):winSize(windowSize) {
		assert(winSize != 0);
	}

    double next(int val) {
        if(window.size()==winSize) {
			rs -= window.front();
			window.pop();
		} 
		rs += val;
		window.push(val);
		return rs/winSize;
    }
};
int main() {
    // MovingAverage m = new MovingAverage(3);
    // m.next(1) = 1
    // m.next(10) = (1 + 10) / 2
    // m.next(3) = (1 + 10 + 3) / 3
    // m.next(5) = (10 + 3 + 5) / 3

    return 0;
}
