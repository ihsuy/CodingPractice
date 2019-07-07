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
A string is a valid parentheses string (denoted VPS) if and only if it consists
of "(" and ")" characters only, and:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example,  "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1,
and 2), and ")(" and "(()" are not VPS's.



Given a VPS seq, split it into two disjoint nonempty subsequences A and B, such
that A and B are VPS's (and A.length + B.length = seq.length).

Now choose any such A and B such that max(depth(A), depth(B)) is the minimum
possible value.

Return an answer array (of length seq.length) that encodes such a choice of A
and B:  answer[i] = 0 if seq[i] is part of A, else answer[i] = 1.  Note that
even though multiple answers may exist, you may return any of them.



Example 1:

Input: seq = "(()())"
Output: [0,1,1,1,1,0]
Example 2:

Input: seq = "()(())()"
Output: [0,0,0,1,1,0,1,1]

*/

// get the depth of nested parentheses strings
// assuming input is in valid format
int depth(const string& seq) {
    int m = 0, res = 0;
    for (auto& ch : seq) {
        if (ch == '(') {
            m++;
            if (m > res)
                res = m;
        } else {
            m--;
        }
    }
    return res;
}

vector<int> maxDepthAfterSplit(const string& seq) {
	// first get the max depth of seq
	// then we know we can only reduce its depth to depth/2 (depth/2 + 1 when depth is odd)
	// by spliting the string in the way that's decribed in the problem
	// we then seperate parenthese that has more than depth/2 in depth
    int d = depth(seq);
    int tard = d / 2, curval = 0;
    vector<int> res(seq.length(), 0);
    for (int i = 0; i < seq.length(); ++i) {
        if (seq[i] == '(') {
            curval++;
        }
        if (curval > tard) {
            res[i] = 1;
        }
        if (seq[i] == ')') {
            curval--;
        }
    }
    return res;
}

int main() {
    return 0;
}
