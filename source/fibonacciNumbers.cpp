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
The Fibonacci numbers, commonly denoted F(n) form a sequence,
called the Fibonacci sequence, such that each number is
the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
*/

int fib(const int& N) {
    if (N < 2) {
        return N;
    }
    long buffer[N + 1];
    memset(buffer, 0, sizeof(long) * (N + 1));

    buffer[1] = 1;
    for (int i = 2; i <= N; ++i) {
        buffer[i] = buffer[i - 1] + buffer[i - 2];
    }
    return buffer[N];
}

int main() {
    cout << fib(30) << '\n';
    return 0;
}
