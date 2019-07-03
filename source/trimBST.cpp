#include <math.h>
#include <algorithm>
#include <chrono>
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
inline void inspect(typename T::iterator i1, typename T::iterator i2) {
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* trimBST(TreeNode* root,
                  int L,
                  int R) {  // first, handle the special cases
    if (root == nullptr) {  // when root is null
        return root;
    }

    if (root->val < L) {  // when root val is less than L
        // we can imply that everything including the root node
        // and all nodes on its left can be trimmed

        // we thus move right
        return trimBST(root->right, L, R);
    }

    if (root->val > R) {  // if the root's value is greater than R, then
        // everything on its right will also be greater
        // than R.

        // we thus move left
        return trimBST(root->left, L, R);
    }

    // if root's value is within the range
    // we check whether if its left and right children
    // are within the range. We then append them to root
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    return root;
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(0);
    head->right = new TreeNode(2);

    trimBST(head, 1, 2);

    return 0;
}
