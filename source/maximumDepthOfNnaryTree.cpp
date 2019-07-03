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
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root
node down to the farthest leaf node.

For example, given a 3-ary tree:


We should return its max depth, which is 3.



Note:

The depth of the tree is at most 1000.
The total number of nodes is at most 5000.

*/

int d = 0;
void smaxDepth(Node* root, const int& n) {
    if (root->children.empty()) {
        d = max(d, n);
        return;
    }
    for (auto& c : root->children) {
        smaxDepth(c, n + 1);
    }
}
int maxDepth(Node* root) {
    if (not root) {
        return 0;
    }
    smaxDepth(root, 1);
    return d;
}

int main() {
    return 0;
}
