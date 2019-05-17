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
Given a string s, find the longest palindromic subsequence's length in s.
You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/

int match(const string& s, const int& l , const int& r, vector<vector<int>>& buffer)
{
    if (l == r)
    {
        return 1;
    }
    if (l > r)
    {
        return 0;
    }
    if (buffer[l][r] != -1)
    {
        return buffer[l][r];
    }
    int temp = 0;
    if (s[l] == s[r])
    {
        temp = match(s, l + 1, r - 1, buffer) + 2;
    }
    else
    {
        auto res1 = match(s, l, r - 1, buffer);
        auto res2 = match(s, l + 1, r, buffer);
        temp = res1 > res2 ? res1 : res2;
    }
    buffer[l][r] = temp;
    return temp;
}
int longestPalindromeSubseq(const string& s) {
    vector<vector<int>> buffer(s.length(), vector<int>(s.length(), -1));
    for (int i = 0; i < s.length(); ++i) {
        buffer[i][i] = 1;
    }
    return match(s, 0, s.length() - 1, buffer);
}

int longestPalindromeSubseq2(string s) 
{
    int sz = s.size();
    if (sz < 2)
        return sz;
    vector<int> dp(sz, 1);
    for (int i = 1; i < sz; i++)
    {
        int pre_j = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            int tmp = dp[j];
            if (s[i] == s[j])
                dp[j] = pre_j + 2;
            else
                dp[j] = max(dp[j] , dp[j + 1]);
            pre_j = tmp;
        }
    }
    return dp[0];
}

int main()
{


    return 0;
}
