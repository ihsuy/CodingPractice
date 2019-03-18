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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<typename T>
inline void inspect(typename T::iterator i1, typename T::iterator i2) {while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

void bfs(vector<vector<char>>& grid, const int& r, const int& c)
{	
	int grid_h = grid.size(), grid_w = grid[0].size();

	queue<pair<int, int>> todo;
	todo.push(pair<int, int>(r, c));

	vector<int> directions{-1, 0, 1, 0, -1};

	while(not todo.empty())
	{
		pair<int, int> p = todo.front();
		todo.pop();

		grid[p.first][p.second] = '2';

		for(int i = 0; i < 4; ++i)
		{
			int cur_r = p.first + directions[i], cur_c = p.second + directions[i+1];
			if(cur_r >= 0 and cur_c >= 0 and cur_r < grid_h and cur_c < grid_w and grid[cur_r][cur_c] == '1')
			{
				grid[cur_r][cur_c] = '2';
				todo.push(pair<int, int>(cur_r, cur_c));
			}
		}
	}
}

int numIslands(vector<vector<char>>& grid) 
{
	int grid_h = grid.size();

	if(grid_h == 0)
	{
		return 0;
	}

	int grid_w = grid[0].size();

	int result = 0;

	for(int i = 0; i < grid_h; ++i)
	{
		for(int j = 0; j < grid_w; ++j)   
		{
			if(grid[i][j] == '1')
			{
				result++;
				bfs(grid, i, j);
			}
		}    
	}

	return result;
}

int main()
{
	vector<vector<char>> grid
	{
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','1'},
		{'0','0','1','1','1'}
	};

	cout << numIslands(grid) << endl;

	return 0;
}
