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
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/

vector<int> findErrorNums(vector<int>& nums) {
    // use bit operation to find the targets
    int n = nums.size();
    // prepare 3 integers with value 0
    int x1 = 0, x2, x3 = x2 = x1;
    // xor everything to get a^b, where a and b are the targets
    // since xor is assciative and communtative, same numbers 
    // will eventually cancel out, hence left with a^b which
    // doesn't have their counterparts to cancel out with.
    for (int i = 1; i <= n; ++i)
        x1 ^= i ^ nums[i - 1];
    // By definition, a must differ from b, thus a^b isn't zero
    // We can then assume nth position in a^b is set
    // which implies a and b have different bit at nth 
    // position.
    // Therefore, all values in nums can be seperated into 2 groups
    // namely, one group where all numbers in it has 1 at their nth
    // position, and another group with 0 at their nth position
    // Next, notice that in nums, by problem definition, the number
    // which is suppposed to be b is set to a
    // that makes aforementioned 2 groups have +1 and -1 elements
    // which will allows us to "force out" a and b by xor'ing original
    // 1~n under the same condition to them.
    int sp = x1 & ~(x1 - 1);
    for (int i = 1; i <= n; ++i) {
        if (nums[i - 1]&sp)
            x2 ^= nums[i - 1];
        else
            x3 ^= nums[i - 1];
        if (i & sp)
            x2 ^= i;
        else
            x3 ^= i;
    }
    // now x2 and x3 must be either a or b
    // and if x2 is not found in nums, it must be b
    // otherwise its a
    if (nums.end() == find(nums.begin(), nums.end(), x2))
    {
        return {x3, x2};
    }
    return {x2, x3};
}

int main()
{


    return 0;
}
