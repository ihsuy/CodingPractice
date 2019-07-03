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

int maxSubArray(vector<int>& nums) {
    int* buffer = new int[nums.size()];
    buffer[0] = nums[0];

    int result = buffer[0];

    for (int i = 1; i < nums.size(); ++i) {
        int prev = buffer[i - 1];
        if (prev <= 0) {
            buffer[i] = nums[i];
        } else {
            buffer[i] = nums[i] + prev;
        }

        if (buffer[i] > result) {
            result = buffer[i];
        }
    }

    return result;
}

int main() {
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(v) << endl;

    return 0;
}
