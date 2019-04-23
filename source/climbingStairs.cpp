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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?
*/

// recursion with memorization
void helper(const int& n, const int& i, long long& way,
            long long* buffer)
{
    if (buffer[i]!=0)
    {
        way += buffer[i];
        return;
    }

    if (n == i)
    {
        way++;
        return;
    }

    helper(n, i + 1, way, buffer);
    buffer[i + 1] = way;
    if (n - i > 1)
    {
        helper(n, i + 2, way, buffer);
        buffer[i + 2] = way;
    }
}

long long climbStairs(int n)
{
    long long result = 0;
    long long* buffer = new long long[n];
    memset(buffer, 0, sizeof(long long)*n);
    helper(n, 0, result, buffer);
    return result;
}

int main()
{   
    int n = 50;
    cout << "number of unique ways: " << climbStairs(n) << '\n';

    return 0;
}
