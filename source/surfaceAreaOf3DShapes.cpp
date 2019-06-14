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
On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.



Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
*/

int dir[5] = { -1, 0, 1, 0, -1};
int surfaceArea(vector<vector<int>>& grid) {
    int w = grid.size(), c = 0;
    for (int i = 0; i < w; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (grid[i][j])
            {
                c += 2;
                for (int d = 0; d < 4; ++d)
                {
                    int nr = i + dir[d], nc = j + dir[d + 1];
                    if (nr<0 or nc<0 or nr >= w or nc >= w)
                    {
                        c += grid[i][j];
                    }
                    else if (grid[i][j] > grid[nr][nc])
                    {
                        c += (grid[i][j] - grid[nr][nc]);
                    }
                }
            }
        }
    }
    return c;
}

int main()
{


    return 0;
}
