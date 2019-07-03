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

int binarySearchIndex(const vector<int>& arr, const int& target, int b, int e) {
    if (b > e) {
        return b;
    }

    int mid = (b + e) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] > target) {
        return binarySearchIndex(arr, target, b, mid - 1);
    } else {
        return binarySearchIndex(arr, target, mid + 1, e);
    }
}

int kEmptySlots_handmade(vector<int>& flowers, int k) {
    vector<int> flowerPots;

    for (int i = 0; i < flowers.size(); ++i) {
        int target_index =
            binarySearchIndex(flowerPots, flowers[i], 0, flowerPots.size() - 1);
        flowerPots.insert(flowerPots.begin() + target_index, flowers[i]);

        if (i == 0) {
            continue;
        } else if (target_index == 0) {  // only look at rhs
            if (flowerPots[target_index + 1] - flowerPots[target_index] - 1 ==
                k) {
                return i + 1;
            }
        } else if (target_index == flowerPots.size() - 1) {  // only look at lhs
            if (flowerPots[target_index] - flowerPots[target_index - 1] - 1 ==
                k) {
                return i + 1;
            }
        } else {  // look left and right
            if ((flowerPots[target_index + 1] - flowerPots[target_index] - 1 ==
                 k) or
                (flowerPots[target_index] - flowerPots[target_index - 1] - 1 ==
                 k)) {
                return i + 1;
            }
        }
    }

    return -1;
}

int kEmptySlots(vector<int>& flowers, int k) {
    set<int> flowerPots;

    for (int i = 0; i < flowers.size(); ++i) {
        auto p = flowerPots.insert(flowers[i]);
        set<int>::iterator iter = p.first;

        if (i == 0) {
            continue;
        } else if ((iter == flowerPots.begin() and
                    (*next(iter, 1) - *iter - 1 == k)) or
                   (iter == (--flowerPots.end()) and
                    (*(iter) - *prev(iter, 1) - 1 == k))) {
            return i + 1;
        } else if ((iter != flowerPots.begin() and
                    iter != (--flowerPots.end())) and
                   ((*next(iter, 1) - *iter - 1 == k) or
                    (*(iter) - *prev(iter, 1) - 1 == k))) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> flowers{1, 2, 3};

    // sort(flowers.begin(), flowers.end());

    inspect<vector<int>>(flowers.begin(), flowers.end());

    // flowers.insert(flowers.begin()+binarySearchIndex(flowers, 5, 0,
    // flowers.size()-1),5);

    // inspect<vector<int>>(flowers.begin(), flowers.end());

    // cout <<flowers[4] << endl;
    cout << kEmptySlots(flowers, 1) << endl;

    return 0;
}
