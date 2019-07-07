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
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a
disjoint union of trees).

Return the roots of the trees in the remaining forest.  You may return the
result in any order. Example 1:

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]


Constraints:

The number of nodes in the given tree is at most 1000.
Each node has a distinct value between 1 and 1000.
to_delete.length <= 1000
to_delete contains distinct values between 1 and 1000.
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void prune(TreeNode* root,
           vector<TreeNode*>& forest,
           TreeNode* prev,
           unordered_set<int>& todel) {
    if (root) {
        prune(root->left, forest, root, todel);
        prune(root->right, forest, root, todel);

        if (todel.count(root->val)) {
            if (prev) {
                if (prev->left == root) {
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }
            }
        } else if (prev == nullptr or todel.count(prev->val)) {
            forest.push_back(root);
        }
    }
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    unordered_set<int> todel(to_delete.begin(), to_delete.end());
    vector<TreeNode*> forest;
    prune(root, forest, nullptr, todel);
    return forest;
}

int main() {
    return 0;
}
