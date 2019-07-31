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
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:

HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?
*/

class HitCounter {
   public:
    vector<pair<int, int>> record;
    long count;
    HitCounter() : count(0) {}

    void hit(int timestamp) {
		// keep track of number of hits on each timestamp that was hit
		// be careful to handle hits on same timestamp
        if (record.size() && (timestamp == record.back().first))
            record.back().second = ++count;
        else
            record.emplace_back(timestamp, ++count);
    }

    int search(const int& ts) {
		// find the largest timestamp in the record that's
		// smaller or equal to 'ts'
        if (record.empty())
            return -1;
        if (ts < record.front().first)
            return -1;
        else if (ts >= record.back().first)
            return record.size() - 1;
        int low = 0, high = record.size() - 1, mid;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (record[mid].first > ts)
                high = mid - 1;
            else if (record[mid].first < ts)
                low = mid + 1;
            else
                return mid;
        }
        return low - 1;
    }

    int getHits(const int& timestamp) {
        int i = search(timestamp), j = search(timestamp - 300);
        return ((i < 0) ? 0 : record[i].second) -
               ((j < 0) ? 0 : record[j].second);
    }
};

int main() {
    return 0;
}
