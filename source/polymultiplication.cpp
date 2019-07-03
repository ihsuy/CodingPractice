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
inline int two(int n) {
    return 1 << n;
}
inline int test(int n, int b) {
    return (n >> b) & 1;
}
inline void set_bit(int& n, int b) {
    n |= two(b);
}
inline void unset_bit(int& n, int b) {
    n &= ~two(b);
}
inline int last_bit(int n) {
    return n & (-n);
}
inline int ones(int n) {
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
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
multiply two polynomials as well as composing them
*/

vector<int> polyMultiplication(const vector<int>& p1, const vector<int>& p2) {
    vector<int> result(p1.size() + p2.size() - 1, 0);

    for (int i = 0; i < p1.size(); ++i) {
        for (int j = 0; j < p2.size(); ++j) {
            result[i + j] += p1[i] * p2[j];
        }
    }
    return result;
}

vector<int> polyPower(
    const vector<int>& p,
    const int& n) {  // taking polynomal p to the n-th power (n>=0)
    if (n == 0) {
        return {1};
    }

    vector<int> result = p;
    for (int i = 0; i < n - 1; ++i) {
        result = polyMultiplication(result, p);
    }

    return result;
}

vector<int> polyAddition(vector<int> p1, vector<int> p2) {
    vector<int> ptr1 = (p1.size() > p2.size()) ? p2 : p1;
    vector<int> ptr2 = (p1.size() > p2.size()) ? p1 : p2;
    // *ptr1 is at most as large as *ptr2
    vector<int> result(ptr2.size());
    for (int i = 0; i < ptr1.size(); ++i) {
        result[i] = ptr1[i] + ptr2[i];
    }
    for (int i = ptr1.size(); i < ptr2.size(); ++i) {
        result[i] = ptr2[i];
    }
    return result;
}

vector<int> polyComposition(const vector<int>& p1,
                            const vector<int>& p2) {  // insert p1 to p2
    vector<int> result = {0};
    for (int i = 0; i < p2.size(); ++i) {
        auto temp_result = polyPower(p1, i);
        temp_result = polyMultiplication(temp_result, {p2[i]});
        result = polyAddition(temp_result, result);
    }
    return result;
}

int main() {
    vector<int> p1{1, 1, 1};
    vector<int> p2{1, -1};
    auto result = polyComposition(p2, p1);
    inspect<vector<int>>(result);
    return 0;
}
