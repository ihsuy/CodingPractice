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
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  The trees are given by root nodes root1 and root2.



Example 1:

Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    bool b1 = root1 == nullptr, b2 = root2 == nullptr;
    // if one of root1 and root2 is nullptr but another one isn't
    // they can't be equivalent, but if both root1 and root2 are
    // nullptr, then they are equivalent.
    if (b1 ^ b2) {
        return false;
    } else if (b1 && b2) {
        return true;
    }
    // if both root1 and root2 aren't nullptr, their values must equal
    if (root1->val != root2->val) {
        return false;
    }
    // for their subtrees to be flipEquiv
    // the above need to be true for one of the following cases
    // namely, flipped or not flipped.
    bool res1 = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    bool res2 = flipEquiv(root1->right, root2->right) && flipEquiv(root1->left, root2->left);
    return res1 || res2;
}

int main()
{


    return 0;
}
