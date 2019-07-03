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
Given an array, convert it to MaximumBinaryTree which is defined as follows.
root node is the maximum element in the given array.
left subtree of a maximumBinaryTree(mbt) is also a mbt thats made from all
numbers on the lhs of the root node right subtree of a mbt is also a mbt and is
made from all elements on the rhs of the root node
*/

TreeNode* build(const vector<int>& nums, const int& l, const int& r) {
    if (l == r) {
        return nullptr;
    }
    int maxval = INT_MIN, maxi = 0;
    for (int i = l; i < r; ++i) {
        if (nums[i] > maxval) {
            maxval = nums[i];
            maxi = i;
        }
    }
    TreeNode* root = new TreeNode(maxval);
    root->left = build(nums, l, maxi);
    root->right = build(nums, maxi + 1, r);
    return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(nums, 0, nums.size());
}

int main() {
    return 0;
}
