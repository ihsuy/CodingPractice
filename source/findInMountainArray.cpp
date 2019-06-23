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
You may recall that an array A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.  If such an index doesn't exist, return -1.

You can't access the mountain array directly.  You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &ma) {
        int low = 0, high = ma.length() - 1, peak = -1;
        while (low != high - 1)
        {
            int mid = (low + high) >> 1;
            int l = ma.get(mid - 1), m = ma.get(mid), r = ma.get(mid + 1);
            if (m > l and m > r)
            {
                peak = mid;
                break;
            }

            if (l < m)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        if (ma.get(peak) == target)
        {
            return peak;
        }
        low = -1, high = peak;
        while (low != high - 1)
        {
            int mid = (low + high) >> 1;
            if (ma.get(mid) < target)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        int p = high;
        if (p < peak and ma.get(p) == target)
        {
            return p;
        }
        low = peak, high = ma.length();
        while (low != high - 1)
        {
            int mid = (low + high) >> 1;
            if (ma.get(mid) <= target)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        p = high;
        if (p < ma.length() and ma.get(p) == target)
        {
            return p;
        }
        return -1;
    }
}

int main()
{


    return 0;
}
