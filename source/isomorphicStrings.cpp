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
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another
character while preserving the order of characters.
No two characters may map to the same character but
a character may map to itself.
*/
void encode(string& s) {
    unordered_map<char, char> encoder;
    char code = '0';
    for (int i = 0; i < s.length(); ++i) {
        if (not encoder.count(s[i])) {
            encoder[s[i]] = code++;
        }
    }
    for (auto& ch : s) {
        ch = encoder[ch];
    }
}
bool isIsomorphic(string s, string t) {
    encode(s);
    encode(t);
    return s == t;
}

bool isIsomorphic_optimal(const string& s, const string& t) {
    int encoder1[257] = {0}, encoder2[257] = {0}, code = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (encoder1[s[i]] != encoder2[t[i]]) {
            return false;
        }
        encoder1[s[i]] = ++code;
        encoder2[t[i]] = code;
    }
    return true;
}

int main() {
    cout << isIsomorphic_optimal("paper", "title") << endl;
    cout << isIsomorphic_optimal("science", "ecneics") << endl;

    return 0;
}
