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

*/

int search(vector<vector<int>>& costs,
           const int& i,
           const int& p,
           vector<vector<int>>& buffer) {
    if (i == costs.size()) {
        return 0;
    }
    if (buffer[i][p] != -1) {
        return buffer[i][p];
    }

    int res1 =
        p == 0 ? INT_MAX : (search(costs, i + 1, 0, buffer) + costs[i][0]);
    int res2 =
        p == 1 ? INT_MAX : (search(costs, i + 1, 1, buffer) + costs[i][1]);
    int res3 =
        p == 2 ? INT_MAX : (search(costs, i + 1, 2, buffer) + costs[i][2]);

    auto res = min(res1, min(res2, res3));
    buffer[i][p] = res;
    return res;
}
int minCost(vector<vector<int>>& costs) {
    vector<vector<int>> buffer(costs.size(), vector<int>(4, -1));
    return search(costs, 0, 3, buffer);
}

int minCost2(vector<vector<int>>& costs) {
    int len = costs.size();
    if (len == 0) {
        return 0;
    }
    for (int i = 1, j = 0; i < len; ++i, ++j) {
        costs[i][0] += min(costs[j][1], costs[j][2]);
        costs[i][1] += min(costs[j][0], costs[j][2]);
        costs[i][2] += min(costs[j][0], costs[j][1]);
    }
    return min(costs[len - 1][0], min(costs[len - 1][1], costs[len - 1][2]));
}

int main() {
    return 0;
}
