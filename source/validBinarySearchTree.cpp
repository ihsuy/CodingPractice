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
Given a binary tree, determine if it is a valid binary search tree (BST).
*/

void inorderTraverse(TreeNode* root, long long& prev_val, bool& bad) {
    if (root == nullptr or bad) {
        return;
    }

    inorderTraverse(root->left, prev_val, bad);

    if (prev_val >= root->val) {
        bad = true;
        return;
    }

    prev_val = root->val;

    inorderTraverse(root->right, prev_val, bad);
}

bool isValidBST(TreeNode* root) {
    bool bad = false;
    long long prev_val = LLONG_MIN;
    inorderTraverse(root, prev_val, bad);
    return not bad;
}

int main() {
    return 0;
}
