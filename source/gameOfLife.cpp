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
#include <thread>

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
Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the

following four rules (taken from the above Wikipedia article):
Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
*/

void markAsLive(int& val)
{	// val is either 1 or 0
	// turn on its second bit
	val |= 2;
}

void markAsDead(int& val)
{
	val &= 1;
}

bool willLive(const int& val)
{
	return (val >> 1);
}

bool isAlive(const int& val)
{
	return val & 1;
}

const vector<int> directions{ -1, -1, 1, 1, -1, 0, 1, 0 , -1};

void determineFate(vector<vector<int>>& board, const int& r, const int& c)
{
	int liveNeighborsCount = 0;

	for (int i = 0; i < 8; ++i)
	{
		int next_r = r + directions[i],
		    next_c = c + directions[i + 1];

		if (next_r >= 0 and next_r < board.size() and next_c >= 0 and next_c < board[0].size()
		        and isAlive(board[next_r][next_c]))
		{
			liveNeighborsCount++;
		}
	}

	if (isAlive(board[r][c]))
	{
		if (liveNeighborsCount < 2 or liveNeighborsCount > 3)
		{
			markAsDead(board[r][c]);
		}
		else if (liveNeighborsCount == 2 or liveNeighborsCount == 3)
		{
			markAsLive(board[r][c]);
		}
	}
	else
	{
		if (liveNeighborsCount == 3)
		{
			markAsLive(board[r][c]);
		}
	}
}

void gameOfLife(vector<vector<int>>& board)
{
	for (int r = 0; r < board.size(); ++r)
	{
		for (int c = 0; c < board[0].size(); ++c)
		{
			determineFate(board, r, c);
		}
	}

	// spawn next state
	for (int r = 0; r < board.size(); ++r)
	{
		for (int c = 0; c < board[0].size(); ++c)
		{
			if (willLive(board[r][c]))
			{
				board[r][c] = 1;
			}
			else
			{
				board[r][c] = 0;
			}
		}
	}
}

int main()
{
	vector<vector<int>> board
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	};
	while (1)
	{
		system("clear");
		gameOfLife(board);

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				cout << board[i][j];
			}
			cout << '\n';
		}
		this_thread::sleep_for(chrono::milliseconds(200));
	}


	return 0;
}



