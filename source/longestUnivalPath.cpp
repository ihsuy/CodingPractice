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

int lup_helper(TreeNode* root, int& result) {
    if (root == NULL) {
        return 0;
    }

    int left = 0, right = 0;

    if (root->left != NULL) {
        left = lup_helper(root->left, result);
        if (root->left->val == root->val) {
            left++;
        } else {
            left = 0;
        }
    }
    if (root->right != NULL) {
        right = lup_helper(root->right, result);
        if (root->right->val == root->val) {
            right++;
        } else {
            right = 0;
        }
    }

    int temp = left + right;

    if (temp > result) {
        result = temp;
    }

    return (left > right) ? left : right;
}

int longestUnivaluePath(TreeNode* root) {
    int result = 0;
    lup_helper(root, result);

    return result;
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(4);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(4);

    head->right = new TreeNode(5);
    head->right->right = new TreeNode(5);

    cout << "result: " << longestUnivaluePath(head) << endl;

    return 0;
}
