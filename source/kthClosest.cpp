#include <math.h>
#include <algorithm>
#include <chrono>
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

/////////////////////////////////////////////////////////////
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> result;
    map<ll, vector<int>> temp;

    for (int i = 0; i < points.size(); ++i) {
        temp[pow(points[i][0], 2) + pow(points[i][1], 2)].push_back(i);
    }

    map<ll, vector<int>>::iterator mi = temp.begin();

    for (int i = 0; i < K; ++i) {
        auto cur = mi->second;
        int j = 0;
        for (; (j < cur.size() and (i + j < K)); ++j) {
            result.push_back(points[cur[j]]);
        }
        i += (j - 1);
        mi++;
    }
    return result;
}

int main() {
    //[[3,3],[5,-1],[-2,4]]
    vector<vector<int>> v = {{1, 0}, {0, 1}};
    vector<vector<int>> v2 = {{3, 3}, {5, -1}, {-2, 4}};
    auto r = kClosest(v, 2);
    for (auto item : r) {
        cout << item[0] << " " << item[1] << endl;
    }
    return 0;
}
