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
This question is about implementing a basic elimination algorithm for Candy Crush.

Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the current board.

 

Example:

Input:
board = 
[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]

Output:
[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
*/

const int crush_n = 3;
int rows = 0, cols = 0;
bool crush(vector<vector<int>>& board)
{
    bool crushed = false;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (board[r][c] != 0)
            {
                bool found = false;
                int ct = 1, i = c + 1, j = r + 1, n = board[r][c];
                while (i < cols)
                {
                    if (board[r][i] != n
                            and board[r][i] != -n)
                    {
                        break;
                    }
                    ct++; i++;
                }
                if (ct >= crush_n)
                {
                    found = true;
                    for (int p = c; p < i; ++p)
                    {
                        if (board[r][p] < 0) continue;
                        board[r][p] = -board[r][p];
                    }
                }
                ct = 1;
                while (j < rows)
                {
                    if (board[j][c] != n
                            and board[j][c] != -n)
                    {
                        break;
                    }
                    ct++; j++;
                }
                if (ct >= crush_n)
                {
                    found = true;
                    for (int p = r; p < j; ++p)
                    {
                        if (board[p][c] < 0) continue;
                        board[p][c] = -board[p][c];
                    }
                }
            }
        }
    }

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (board[r][c] < 0)
            {
                if (not crushed)
                {
                    crushed = true;
                }
                board[r][c] = 0;
            }
        }
    }
    return crushed;
}

void drop(vector<vector<int>>& board)
{
    vector<vector<int>> b(rows, vector<int>(cols, 0));
    for (int c = 0; c < cols; ++c)
    {
        for (int r = rows - 1, k = rows - 1; r >= 0; --r)
        {
            if (board[r][c] != 0)
            {
                b[k--][c] = board[r][c];
            }
        }
    }
    board = b;
}

vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    rows = board.size(), cols = board[0].size();
    while (crush(board))
    {
        drop(board);
    }
    return board;
}

int main()
{
    /*test cases omitted*/

    return 0;
}
