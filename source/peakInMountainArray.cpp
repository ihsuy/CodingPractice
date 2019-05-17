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
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain,
return any i such that A[0] < A[1] < ... A[i-1]
< A[i] > A[i+1] > ... > A[A.length - 1].
*/

int peakIndexInMountainArray1(vector<int>& A) {
    int i = 0; while (A[i] < A[i++ +1]);
    return i - 1;
}

int peakIndexInMountainArray2(vector<int>& A) {
    int l = 0;
    for (int h = A.size() - 1; l < h;)
    {
        int mid = (l + h) >> 1;
        if (A[mid] < A[mid + 1])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return l;
}

int main()
{


    return 0;
}
