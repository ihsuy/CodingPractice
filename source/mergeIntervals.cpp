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
inline int two(int n) {
    return 1 << n;
}
inline int test(int n, int b) {
    return (n >> b) & 1;
}
inline void set_bit(int& n, int b) {
    n |= two(b);
}
inline void unset_bit(int& n, int b) {
    n &= ~two(b);
}
inline int last_bit(int n) {
    return n & (-n);
}
inline int ones(int n) {
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
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
Given a collection of intervals, merge all overlapping intervals.
*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval> intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(),
         [](Interval& i1, Interval& i2) { return i1.start < i2.start; });

    vector<Interval> result;

    for (int i = 1; i < intervals.size(); ++i) {
        bool merged = false;

        if (intervals[i].start >= intervals[i - 1].start and
            intervals[i].start <= intervals[i - 1].end) {
            intervals[i].start = intervals[i - 1].start;
            intervals[i].end = (intervals[i].end > intervals[i - 1].end)
                                   ? intervals[i].end
                                   : intervals[i - 1].end;

            merged = true;
        }

        if (not merged) {
            result.push_back(intervals[i - 1]);
        }

        if (i == intervals.size() - 1) {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {
    vector<Interval> intervals{Interval(1, 3), Interval(2, 6), Interval(8, 10),
                               Interval(15, 18)};

    auto result = merge(intervals);

    cout << "merged intervals: \n";

    for (auto& interval : result) {
        cout << '[' << interval.start << ", " << interval.end << "]\n";
    }

    return 0;
}
