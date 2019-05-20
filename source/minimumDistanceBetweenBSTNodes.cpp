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
Given a Binary Search Tree (BST) with the root node root, return the
 minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \
    1   3

while the minimum difference in this tree is 1, it occurs between node 1 and
node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's
value is different.
*/

class Solution {
public:
    int prev, min_dif;
    Solution()
    {
        prev = INT_MIN;
        min_dif = INT_MAX;
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    void check(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        check(root->left);
        int dif = prev == INT_MIN ? INT_MAX : root->val - prev;
        if (dif < min_dif)
        {
            min_dif = dif;
        }
        prev = root->val;
        check(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        check(root);
        return min_dif;
    }
};

int main()
{


    return 0;
}
