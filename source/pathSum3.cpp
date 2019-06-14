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
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

int res = 0;
void search(TreeNode* root, const int& sum, vector<int>& path)
{
    if (not root)
    {
        return;
    }
    if (root->val == sum)
    {
        res++;
    }
    for (int i = path.size() - 1, s = root->val; i >= 0; --i)
    {
        s += path[i];
        if (s == sum)
        {
            res++;
        }
    }
    path.push_back(root->val);
    search(root->left, sum, path);
    search(root->right, sum, path);
    path.pop_back();
}
int pathSum(TreeNode* root, int sum) {
    vector<int> path;
    search(root, sum, path);
    return res;
}

int main()
{


    return 0;
}
