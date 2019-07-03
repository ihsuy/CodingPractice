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
inline int two(int n) {
    return 1 << n;
}
inline int test(int n, int b) {
    return (n >> b) & 1;
}
inline void set_bit(int& n, int b) {
    n |= two(b);
}
inline void unset_bit(int& n, int b) {
    n &= ~two(b);
}
inline int last_bit(int n) {
    return n & (-n);
}
inline int ones(int n) {
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
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
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two
nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \
      4   5
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getNNode(TreeNode* root, int& result) {  // get number of nodes of
    // the longest path that go through root
    if (root == nullptr) {
        return 0;
    }
    // recursively calculate for each node in the tree
    int left_nNode = getNNode(root->left, result);
    int right_nNode = getNNode(root->right, result);

    // used the the result to update final "result"
    result = max(result, left_nNode + right_nNode + 1);

    // function return the larger nNode for the calculation of 1 level above
    return max(left_nNode, right_nNode) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {  // if there's no tree
    // there's only 1 or no nodes at all
    // the initial result = 1 because there's 1 or 0 nodes
    // and choosing initial value to be 1 will help deal with
    // when root is nullptr we can return 0 otherwise it returns -1
    int result = 1;
    getNNode(root, result);
    // minus 1 to get the length of edge
    return result - 1;
}

int main() {
    return 0;
}
