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
Given a binary tree and a sum, determine if the tree has
a root-to-leaf path such that adding up all the
values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf
path 5->4->11->2 which sum is 22.
*/

bool hasPathSum(TreeNode* root, int sum, const int& temp = 0)
{
    if (not root)
    {
        return false;
    }
    if (not root->left and not root->right)
    {
        return temp + root->val == sum;
    }
    return hasPathSum(root->left, sum, temp + root->val)
           or hasPathSum(root->right, sum, temp + root->val);
}

int main()
{
    // test cases omitted

    return 0;
}
