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
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
*/

bool wordPattern(string pattern, string str) {
    unordered_map<char, string> buffer;
    unordered_map<string, char> rbuffer;
    stringstream ss(str);
    string word;
    int i = 0;
    for (; i < pattern.length() and ss >> word; ++i) {
        if (buffer.count(pattern[i]) == 0) {
            if (rbuffer.count(word) != 0) {
                return false;
            }
            buffer[pattern[i]] = word;
            rbuffer[word] = pattern[i];
        } else if (buffer[pattern[i]] != word) {
            return false;
        }
    }
    if (not ss.eof() or i != pattern.length()) {
        return false;
    }
    return true;
}

int main() {
    return 0;
}
