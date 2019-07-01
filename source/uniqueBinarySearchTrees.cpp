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
Given an integer n, generate all structurally unique BST's (binary search trees)
that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<TreeNode*> makeTrees(const int& begin, const int& end) {
    if (begin > end) {
        return {nullptr};
    }
    vector<TreeNode*> t;
    for (int i = begin; i <= end; ++i) {
        auto left = makeTrees(begin, i - 1), right = makeTrees(i + 1, end);
        for (int a = 0; a < left.size(); ++a) {
            for (int b = 0; b < right.size(); ++b) {
                TreeNode* root = new TreeNode(i);
                root->left = left[a];
                root->right = right[b];
                t.push_back(root);
            }
        }
    }
    return t;
}
vector<TreeNode*> generateTrees(int n) {
    if (!n) {
        return {};
    }
    return makeTrees(1, n);
}

int main() {
    return 0;
}
