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
Given a string S that only contains "I" (increase) or "D" (decrease),
let N = S.length.

Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
*/

vector<int> diStringMatch(string S) {
    vector<int> result;
    result.reserve(S.length() + 1);
    int a = 0;
    for (int i = 0, b = S.length(); i < S.length(); ++i) {
        if (S[i] == 'I') {
            result.push_back(a++);
        } else {
            result.push_back(b--);
        }
    }
    result.push_back(a);
    return result;
}

int main() {
    return 0;
}
