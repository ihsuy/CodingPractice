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
There is a ball in a maze with empty spaces and walls. The ball can go through
empty spaces by rolling up, down, left or right, but it won't stop rolling until
hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, determine whether
the ball could stop at the destination.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the
empty space. You may assume that the borders of the maze are all walls. The
start and destination coordinates are represented by row and column indexes.



Example 1:

Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
*/

const int dir[5] = {-1, 0, 1, 0, -1};
int rows, cols;

bool valid(const int& next_r, const int& next_c, const vector<vector<int>>& maze) {
    return next_r >= 0 && next_r < rows && next_c >= 0 && next_c < cols && !maze[next_r][next_c];
}

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
	// no need to search if the start is already at the destination
    if (start.front() == destination.front() && start.back() == destination.back()) {
        return true;
    }
    rows = maze.size(), cols = maze.front().size();
	// keep track of locations we have been to so that 
	// we can terminate the search whenever we arrive at the same location again
    set<pair<int, int>> beenHere;
	beenHere.insert({start[0], start[1]});
	// bfs
    queue<pair<int, int>> pos;
    pos.emplace(start[0], start[1]);
    while (!pos.empty()) {
        auto p = pos.front();
        pos.pop();
        for (int i = 0; i < 4; ++i) {
			// for each of the 4 directions, try to roll ahead until it hits the 'wall'
            int next_r = p.first + dir[i], next_c = p.second + dir[i + 1];
            if (valid(next_r, next_c, maze)) {
                do {
                    next_r += dir[i];
                    next_c += dir[i + 1];
                } while (valid(next_r, next_c, maze));
				// roll back 1 step to the last 'valid' location
                pair<int, int> here{next_r - dir[i], next_c - dir[i + 1]};
				// been here already?
                if (beenHere.count(here)) {
                    continue;
                }
				// no, then record it as "been here"
                beenHere.insert(here);
				// arrived at the destination?
                if (here.first == destination.front() && here.second == destination.back()) {
                    return true;
                }
				// no, then set 'here' to be a search starting point candidate
                pos.push(here);
            }
        }
    }
    return false;
}

int main() {
    return 0;
}
