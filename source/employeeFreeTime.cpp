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
We are given a list schedule of employees, which represents the working time for
each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are
in sorted order.

Return the list of finite intervals representing common, positive-length free
time for all employees, also in sorted order.

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.


Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]


(Even though we are representing Intervals in the form [x, y], the objects
inside are Intervals, not lists or arrays. For example, schedule[0][0].start =
1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero
length.

Note:

schedule and schedule[i] are lists with lengths in range [1, 50].
0 <= schedule[i].start < schedule[i].end <= 10^8.
*/

vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
    vector<pair<int, int>> p;
    for (auto& sd : schedule) {
        for (auto& itv : sd) {
            p.push_back({itv[0], 1});
            p.push_back({itv[1], -1});
        }
    }
    sort(p.begin(), p.end());
    vector<vector<int>> res;
    int k = 0;
    for (int i = 0; i < p.size() - 1; ++i) {
        k += p[i].second;
        if (k == 0 and p[i].first != p[i + 1].first) {
            res.push_back({p[i].first, p[i + 1].first});
        }
    }
    return res;
}

int main() {
    return 0;
}
