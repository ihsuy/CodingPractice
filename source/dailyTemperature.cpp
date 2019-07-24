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
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

vector<int> dailyTemperatures(vector<int>& t) {
    vector<int> res(t.size(), 0);
    stack<pair<int, int>> q;
	// iterate backward and use a stack to keep track of possible date candidates
    for (int i = t.size() - 1; i >= 0; --i) {
		// remove item from stack until we get a warmer temperature or run out of record
        while (!q.empty() && q.top().first <= t[i]) {
            q.pop();
        }
		// if we run out of record, then the result for this date is 0 as defined
		// else we found warmer temperature, we then substract its index with the 
		// current index.
        if (q.empty()) {
            res[i] = 0;
        } else {
            res[i] = q.top().second - i;
        }
		// track this temperature
        q.emplace(t[i], i);
    }
    return res;
}

int main() {
    return 0;
}
