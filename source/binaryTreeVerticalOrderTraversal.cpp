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
Given a binary tree, return the vertical
order traversal of its nodes' values.
(ie, from top to bottom, column by column).

If two nodes are in the same row and column,
the order should be from left to right.

Input: [3,9,8,4,0,1,7,null,null,null,2,5]
(0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(TreeNode* root)
{
	if (root == nullptr)
	{
		return vector<vector<int>>();
	}

	vector<vector<int>> result;

	// use the map data structure to keep track of 
	// vals in each vertical level while keeping levels in order
	map<int, vector<int>> vertical_levels;

	// do a bfs

	// the int in the pair is an unique name for each level
	queue<pair<int, TreeNode*>> todo;
	todo.push({0, root});

	while (not todo.empty())
	{
		auto p = todo.front();
		todo.pop();

		int nlevel = p.first;
		TreeNode* current_node = p.second;

		vertical_levels[nlevel].push_back(current_node->val);

		if (current_node->left != nullptr)
		{	// the we go left by 1, the level name will decrease by 1
			todo.push({nlevel - 1, current_node->left});
		}
		if (current_node->right != nullptr)
		{
			todo.push({nlevel + 1, current_node->right});
		}
	}

	for (auto ite = vertical_levels.begin(); ite != vertical_levels.end(); ++ite)
	{
		result.push_back(ite->second);
	}

	return result;
}

int main()
{


	return 0;
}
