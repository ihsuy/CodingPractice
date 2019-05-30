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
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

int numSquares(int n) {
    if (n == 1) return 1;
    int dp[n + 1] = {0}; dp[1] = 1; dp[2] = 2;
    for (int i = 3, sq = 4, q = 2; i <= n; ++i)
    {
        if (i == sq)
        {
            dp[i] = 1;
            sq = (++q) * q;
        }
        else
        {
            int temp = n;
            for (int j = 1; j * j < i; ++j)
            {
                int step = dp[i - j * j] + 1;
                if (step < temp)
                {
                    temp = step;
                }
            }
            dp[i] = temp;
        }
    }
    return dp[n];
}

int main()
{


    return 0;
}
