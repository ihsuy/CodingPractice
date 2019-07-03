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
Winter is coming! Your first job during the contest is to design a standard
heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find
out minimum radius of heaters so that all houses could be covered by those
heaters.

So, your input will be the positions of houses and heaters seperately, and your
expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed
25000. Positions of houses and heaters you are given are non-negative and will
not exceed 10^9. As long as a house is in the heaters' warm radius range, it can
be warmed. All the heaters follow your radius standard and the warm radius will
the same.


Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the
radius 1 standard, then all the houses can be warmed.
*/

int findRadius(vector<int>& houses, vector<int>& heaters) {
    // Perform binary search in heater locations for each house locations.
    // In other words, find heater that's closest to each house.
    sort(heaters.begin(), heaters.end());
    int diff = 0;
    for (int i = 0; i < houses.size(); ++i) {
        int dif = 0;
        // binary search
        auto lbi = lower_bound(heaters.begin(), heaters.end(), houses[i]);
        // handle corner cases
        if (lbi == heaters.end())
            dif = abs(houses[i] - *(lbi - 1));
        else if (lbi == heaters.begin())
            dif = abs(houses[i] - *lbi);
        else
            dif = min(abs(houses[i] - *(lbi - 1)), abs(houses[i] - *lbi));
        // update the largest radius
        if (dif > diff)
            diff = dif;
    }
    return diff;
}

int main() {
    return 0;
}
