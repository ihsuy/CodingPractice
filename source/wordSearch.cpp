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
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
const int dir[5] = {-1, 0, 1, 0, -1};
int rows, cols;
bool search(vector<vector<char>>& board,
            const string& word,
            const int& r,
            const int& c,
            const int& index) {
    if ((r < 0 or c < 0 or r >= rows or c >= cols) or board[r][c] == 0 or
        board[r][c] != word[index])
        return false;

    if (index == word.length() - 1)
        return true;

    bool res = false;
    auto temp = board[r][c];
    board[r][c] = 0;
    for (int i = 0; i < 4; ++i) {
        if (search(board, word, r + dir[i], c + dir[i + 1], index + 1)) {
            res = true;
            break;
        }
    }
    board[r][c] = temp;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    rows = board.size();
    cols = board[0].size();
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (search(board, word, r, c, 0))
                return true;
        }
    }
    return false;
}

int main() {
    return 0;
}
