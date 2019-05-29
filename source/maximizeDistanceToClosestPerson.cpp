#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <list>
#include <chrono>
#include <random>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <bitset>
#include <fstream>
#include <string>

typedef long long ll;
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation:
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.
*/

int maxDistToClosest(vector<int>& seats) {
    int f = -1, l = f;
    for (int i = 0; i < seats.size(); ++i)
    {
        if (seats[i])
        {
            f = i;
            break;
        }
    }
    for (int i = seats.size() - 1; i >= 0; --i)
    {
        if (seats[i])
        {
            l = i;
            break;
        }
    }
    int lres = seats.size() - l - 1;

    int res = 0;
    for (int i = f; i <= l; ++i)
    {
        int c = 0;
        while (not seats[i])
        {
            c++;
            i++;
        }
        c = (c + 1) >> 1;
        if (c > res)
        {
            res = c;
        }
    }
    return max(res, max(f, lres));
}

int main()
{


    return 0;
}
