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
Given an array A of strings made only from lowercase letters, return a list of
all characters that show up in all strings within the list (including
duplicates).  For example, if a character occurs 3 times in all strings but not
4 times, you need to include that character three times in the final answer.

You may return the answer in any order.



Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]


Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/

vector<string> commonChars(vector<string>& A) {
    int counter[27] = {0};
    for (auto& ch : A[0]) {
        counter[ch - 'a']++;
    }

    for (int i = 1; i < A.size(); ++i) {
        int c[27] = {0};
        for (auto& ch : A[i]) {
            c[ch - 'a']++;
        }
        for (int j = 0; j < 27; ++j) {
            counter[j] = min(counter[j], c[j]);
        }
    }
    vector<string> res;
    for (int i = 0; i < 27; ++i) {
        for (int j = 0; j < counter[i]; ++j) {
            res.push_back(string(1, i + 'a'));
        }
    }
    return res;
}
int main() {
    return 0;
}
