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
Find the kth largest element in an unsorted array. Note that it is the kth
largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

int findKthLargest(vector<int>& nums, int k) {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int low = 0, high = nums.size();
    while (low < high) {
        int pivot = rand() % (high - low), p = low;
        swap(nums[low], nums[low + pivot]);
        for (int i = low + 1; i < high; ++i)
            if (nums[i] < nums[low])
                swap(nums[i], nums[++p]);
        swap(nums[low], nums[p]);
        if (nums.size() - p == k)
            return nums[p];
        else if (nums.size() - p > k)
            low = p + 1;
        else
            high = p;
    }
    return 0;
}

int main() {
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 3;
    cout << "result: " << findKthLargest(nums, k) << '\n';
    return 0;
}
