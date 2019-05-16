#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <list>
#include <chrono>
#include <random>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <bitset>
#include <fstream>
#include <string>

typedef long long ll;
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given an integer array, find three numbers whose product
is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6


Example 2:

Input: [1,2,3,4]
Output: 24
*/

int maximumProduct(vector<int>& nums)
{
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] > max2)
        {
            max3 = max2;
            max2 = nums[i];
        }
        else if (nums[i] > max3)
        {
            max3 = nums[i];
        }

        if (nums[i] < min1)
        {
            min2 = min1;
            min1 = nums[i];
        }
        else if (nums[i] < min2)
        {
            min2 = nums[i];
        }
    }
    int mul1 = max2 * max3, mul2 = min1 * min2;
    return (mul1 > mul2) ? mul1 * max1 : mul2 * max1;
}

int main()
{


    return 0;
}
