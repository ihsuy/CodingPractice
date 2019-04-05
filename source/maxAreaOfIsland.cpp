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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical.)
You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array.
(If there is no island, the maximum area is 0.)
*/

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	vector<int> directions = {1, 0, -1, 0, 1};

	int max_area = 0;

	int gridh = grid.size(), gridw = grid[0].size();

	for(int r = 0; r < gridh; ++r)
	{
		for(int c = 0; c < gridw; ++c)
		{
			if(grid[r][c] == 1)
			{	// this is a valid starting point
				// search and count 1s
				queue<pair<int, int>> todo;

				todo.push({r,c});

				grid[r][c] = 2; // mark visited

				int area = 1;

				while(not todo.empty())
				{
					auto p = todo.front();
					todo.pop();

					for(int d = 0; d < 4; ++d)
					{
						int peek_r = p.first + directions[d],
							peek_c = p.second + directions[d+1];
						if(peek_r >= 0 and peek_c >= 0 and peek_r < gridh and peek_c < gridw
							and grid[peek_r][peek_c] == 1)
						{
							todo.push({peek_r, peek_c});

							grid[peek_r][peek_c] = 2;
							area ++;
						}
					}
				}

				// compare with max_area and update
				if(area > max_area)
				{
					max_area = area;
				}
			}
		}
	}
	return max_area;
}

int main()
{
	vector<vector<int>> grid1
	{
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
	};

	vector<vector<int>> grid2
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	
	cout << "grid1 result: " << maxAreaOfIsland(grid) << endl;
	
	cout << "grid2 result: " << maxAreaOfIsland(grid2) << endl;

	return 0;
}
