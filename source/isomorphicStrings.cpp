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
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another
character while preserving the order of characters.
No two characters may map to the same character but
a character may map to itself.
*/
void encode(string& s)
{
    unordered_map<char, char> encoder;
    char code = '0';
    for (int i = 0; i < s.length(); ++i)
    {
        if (not encoder.count(s[i]))
        {
            encoder[s[i]] = code++;
        }
    }
    for (auto& ch : s)
    {
        ch = encoder[ch];
    }
}
bool isIsomorphic(string s, string t) {
    encode(s);
    encode(t);
    return s == t;
}

int main()
{


    return 0;
}
