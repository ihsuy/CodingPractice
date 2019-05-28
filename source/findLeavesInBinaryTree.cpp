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
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

 

Example:

Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

Output: [[4,5,3],[2],[1]]

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int>> res;
bool isLeaf(TreeNode* root)
{
    if (not root or root->left or root->right)
    {
        return false;
    }
    return true;
}
void chigiru(TreeNode* root, vector<int>& leafs)
{
    if (not root)
    {
        return;
    }
    bool leftIsLeaf = isLeaf(root->left),
         rightIsLeaf = isLeaf(root->right);
    if (leftIsLeaf)
    {   // remove leaf (better if we delete it)
        leafs.push_back(root->left->val);
        root->left = nullptr;
    }
    else
    {   // go deeper to find leaf nodes
        chigiru(root->left, leafs);
    }
    if (rightIsLeaf)
    {
        leafs.push_back(root->right->val);
        root->right = nullptr;
    }
    else
    {
        chigiru(root->right, leafs);
    }
}
vector<vector<int>> findLeaves(TreeNode* root) {
    if (not root)
    {
        return {};
    }
    while (not isLeaf(root))
    {
        vector<int> leafs;
        chigiru(root, leafs);
        res.push_back(leafs);
    }
    res.push_back({root->val});
    return res;
}

int main()
{


    return 0;
}
