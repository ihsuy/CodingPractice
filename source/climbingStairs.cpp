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
void helper(const int& n, const int& i, unsigned long long& way,
            unsigned long long* buffer)
{
    if (buffer[i] != 0)
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

unsigned long long climbStairs(const int& n)
{
    unsigned long long result = 0;
    unsigned long long* buffer = new unsigned long long[n];
    memset(buffer, 0, sizeof(unsigned long long)*n);
    helper(n, 0, result, buffer);
    return result;
}

unsigned long long climbStairs_dp(const int& n)
{
    if (n <= 1)
    {
        return max(n, 0);
    }

    unsigned long long* dp = new unsigned long long[n];
    memset(dp, 0, sizeof(unsigned long long)*n);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    auto res = dp[n];
    delete[] dp;
    return res;
}

// even faster, using matrix multiplication
unsigned long long climbStairs_matrixMul(const int& n)
{
    if (n <= 1)
    {
        return max(n, 0);
    }
    unsigned long long m[4] = {1, 1, 1, 0};
    unsigned long long temp;
    for (int i = 0; i < n - 1; ++i)
    {
        temp = m[0];
        m[0] += m[1];
        m[1] = temp;
        temp = m[2];
        m[2] += temp;
        m[3] = temp;
    }
    return m[0];
}

// since we've realize this problem is actually asking for
// the n th fibonacci number
// apply the formula directly
unsigned long long climbStairs_formula(const int& n)
{
    double sqrt5 = sqrt(5);
    double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    return (int)(fibn / sqrt5);
}

pair<unsigned long long, unsigned long long>
run(unsigned long long(climb)(const int&), const int& n)
{
    auto t1 = chrono::high_resolution_clock::now();
    auto res = climb(n);
    auto t2 = chrono::high_resolution_clock::now() - t1;
    auto t = chrono::duration_cast<chrono::nanoseconds>(t2).count();
    return {t, res};
}

int main()
{
    int n = 40;
    cout << "number of unique ways:\n";
    auto res1 = run(climbStairs, n);
    auto res2 = run(climbStairs_dp, n);
    auto res3 = run(climbStairs_matrixMul, n);
    auto res4 = run(climbStairs_formula, n);

    const char* schema = "\n%s\n%i test case, time spent: %i nanoseconds\nanswer: %i\n";
    printf(schema, "recursive  ", n, res1.first, res1.second);
    printf(schema, "dp         ", n, res2.first, res2.second);
    printf(schema, "matrixmul  ", n, res3.first, res3.second);
    printf(schema, "fib formula", n, res4.first, res4.second);
    return 0;
}
