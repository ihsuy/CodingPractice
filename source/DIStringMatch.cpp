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
    for (int i = 0, b = S.length(); i < S.length(); ++i)
    {
        if (S[i] == 'I')
        {
            result.push_back(a++);
        }
        else
        {
            result.push_back(b--);
        }
    }
    result.push_back(a);
    return result;
}

int main()
{


    return 0;
}
