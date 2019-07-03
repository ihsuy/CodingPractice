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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(
    TreeNode* root) {  // do a pre-order traverse and swap all nodes' childs
    if (root == NULL) {
        return NULL;
    }

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    // swap it
    if (root->left != NULL or root->right != NULL) {
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    return root;
}

int main() {
    return 0;
}
