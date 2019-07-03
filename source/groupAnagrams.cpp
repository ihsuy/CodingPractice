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
Given an array of strings, group anagrams together.
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    for (int i = 0; i < strs.size(); ++i) {
        string sortedWord = strs[i];
        sort(sortedWord.begin(), sortedWord.end());
        anagrams[sortedWord].push_back(strs[i]);
    }
    vector<vector<string>> result;
    for (auto ite = anagrams.begin(); ite != anagrams.end(); ++ite) {
        result.push_back(ite->second);
    }
    return result;
}

int main() {
    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};

    auto result = groupAnagrams(v);

    for (int i = 0; i < result.size(); ++i) {
        inspect<vector<string>>(result[i]);
    }

    return 0;
}
