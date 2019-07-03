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
You are driving a vehicle that has capacity empty seats initially available for
passengers.  The vehicle only drives east (ie. it cannot turn around and drive
west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location]
contains information about the i-th trip: the number of passengers that must be
picked up, and the locations to pick them up and drop them off.  The locations
are given as the number of kilometers due east from your vehicle's initial
location.

Return true if and only if it is possible to pick up and drop off all passengers
for all the given trips.
*/
bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> k(1001, 0);
    for (int i = 0; i < trips.size(); ++i) {
        for (int j = trips[i][1]; j < trips[i][2]; ++j) {
            k[j] += trips[i][0];
            if (k[j] > capacity) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    return 0;
}
