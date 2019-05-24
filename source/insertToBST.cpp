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
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
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
class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cout.tie(0); cin.tie(0);
    }
    TreeNode* insert(TreeNode* root, const int& val)
    {
        if (not root)
        {
            return new TreeNode(val);
        }
        if (val > root->val)
        {
            root->right = insert(root->right, val);
        }
        else
        {
            root->left = insert(root->left, val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        if (not root)
        {
            return new TreeNode(val);
        }

        return insert(root, val);
    }
};

int main()
{


    return 0;
}
