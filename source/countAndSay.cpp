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
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.
*/

string countAndSay(const int& n) 
{
    if (n == 1)
    {
        return "1";
    }
    if (n == 2)
    {
        return "11";
    }

    string s = countAndSay(n - 1), res;
    for (int i = 1, c = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            c++;
        }
        else
        {
            res += to_string(c) + s[i - 1];
            c = 1;
        }

        if (i == s.length() - 1 and c != 1)
        {
            res += to_string(c) + s[i - 1];
        }
        else if (i == s.length() - 1)
        {
            res += "1" + string(1, s[i]);
        }
    }
    return res;
}

int main()
{


    return 0;
}
