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
Given a non-empty binary search tree and a target value,
find the value in the BST that is closest to the target.
*/
int closestValue(TreeNode* root, double target) {
    if (root == nullptr) {
        return -1;
    }
    int high = root->val, low = root->val;
    bool highUpdated = false, lowUpdated = false;
    while (root != nullptr) {
        if (root->val > target) {
            highUpdated = true;
            high = root->val;
            root = root->left;
        } else if (root->val < target) {
            lowUpdated = true;
            low = root->val;
            root = root->right;
        } else {
            return target;
        }
    }

    if (not highUpdated) {
        return low;
    }
    if (not lowUpdated) {
        return high;
    }

    return ((high - target) < (target - low)) ? high : low;
}

int main() {
    return 0;
}
