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
In Pascal's triangle, each number is the
sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

int getVal(const int& r, const int& c, const vector<vector<int>>& p)
{
    if (c == 0 or r == c)
    {
        return 1;
    }
    return ((p[r - 1][c - 1] != 0) ? p[r - 1][c - 1] : getVal(r - 1, c - 1, p))
           + ((p[r - 1][c] != 0) ? p[r - 1][c] : getVal(r - 1, c, p));
}
vector<vector<int>> generate(const int& n)
{
    vector<vector<int>> p;
    for (int r = 0, uc = 1; r < n; ++r, ++uc)
    {
        vector<int> layer;
        for (int c = 0; c < uc; ++c)
        {
            layer.push_back(0);
        }
        p.push_back(layer);
    }
    for (int r = 0, uc = 1; r < n; ++r, ++uc)
    {
        for (int c = 0; c < uc; ++c)
        {
            p[r][c] = getVal(r, c, p);
        }
    }
    return p;
}

int main()
{


    return 0;
}
