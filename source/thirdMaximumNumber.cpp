#include <math.h>
#include <algorithm>
#include <bitset>
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
Given a non-empty array of integers, return the third maximum number in this
array. If it does not exist, return the maximum number. The time complexity must
be in O(n).
*/

int thirdMax(vector<int>& nums) {
    int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN;

    bool test_Case_Makers_Brain_Is_F__ked = TRUE;

    unordered_set<int> counterF__k;

    for (int i = 0; i < nums.size(); ++i) {
        int cur_val = nums[i];
        counterF__k.insert(cur_val);

        if (cur_val > m1) {
            m3 = m2;
            m2 = m1;
            m1 = cur_val;
        } else if (cur_val > m2 and cur_val != m1) {
            m3 = m2;
            m2 = cur_val;
        } else if (cur_val > m3 and cur_val != m1 and cur_val != m2) {
            m3 = cur_val;
        }
    }
    if (counterF__k.size() < 3) {
        return m1;
    }
    return m3;
}

int main() {
    vector<int> v{1, 2, INT_MIN};

    cout << "third maximum number:\n" << thirdMax(v) << '\n';

    sort(v.begin(), v.end());

    inspect<vector<int>>(v);

    return 0;
}
