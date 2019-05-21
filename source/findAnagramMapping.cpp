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
Given two lists Aand B, and B is an anagram of A. B 
is an anagram of A means B is made by randomizing 
the order of the elements in A.

We want to find an index mapping P, from A to B. A 
mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there 
are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
We should return
[1, 4, 3, 2, 0]
as P[0] = 1 because the 0th element of A appears 
at B[1], and P[1] = 4 because the 1st element of A
 appears at B[4], and so on.
Note:

A, B have equal lengths in range [1, 100].
A[i], B[i] are integers in range [0, 10^5].
*/

vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    unordered_map<int, int> m;
    for (int i = 0; i < B.size(); ++i)
    {
        m[B[i]] = i;
    }
    vector<int> result;
    for (int i = 0; i < A.size(); ++i)
    {
        result.push_back(m[A[i]]);
    }
    return result;
}

int main()
{


    return 0;
}
