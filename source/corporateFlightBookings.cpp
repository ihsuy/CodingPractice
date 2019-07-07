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
There are n flights, and they are labeled from 1 to n.

We have a list of flight bookings.  The i-th booking bookings[i] = [i, j, k] means that we booked k seats from flights labeled i to j inclusive.

Return an array answer of length n, representing the number of seats booked on each flight in order of their label.

 

Example 1:

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
*/

// be careful this problem has a strict limit on runtime
// naive approach that increments numbers one by one in the range [bookings[0], bookings[1]]
// won't pass.
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> b(n + 1, 0);
    for (auto& bk : bookings) {
        b[bk[0] - 1] += bk.back();
        b[bk[1]] -= bk.back();
    }
    int rs = 0;
    for (int i = 0; i < n; ++i) {
        rs += b[i];
        b[i] = rs;
    }
    b.pop_back();
    return b;
}

int main() {
    return 0;
}
