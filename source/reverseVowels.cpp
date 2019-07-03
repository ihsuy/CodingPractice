#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
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
Write a function that takes a string as input and reverse only the vowels of a
string
*/

unordered_set<char> vowels_list{'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

string reverseVowels(
    string s) {  // straight forward seperate reverse and merge approach
    vector<int> indices;
    indices.reserve(s.length());

    vector<int> vowels;
    vowels.reserve(s.length());

    for (int i = 0; i < s.length(); ++i) {
        char cur_char = s[i];
        if (vowels_list.count(cur_char)) {
            vowels.push_back(cur_char);
            indices.push_back(i);
        }
    }

    reverse(vowels.begin(), vowels.end());
    for (int i = 0; i < indices.size(); ++i) {
        s[indices[i]] = vowels[i];
    }

    return s;
}

string reverseVowels2(string s) {  // inplace reverse
    int p1 = 0;
    int p2 = s.length();
    char temp;

    while (p1 < p2) {
        while (not vowels_list.count(s[p1]) and p1 < p2) {
            p1++;
        }

        while (not vowels_list.count(s[p2]) and p1 < p2) {
            p2--;
        }

        temp = s[p1];
        s[p1] = s[p2];
        s[p2] = temp;

        p1++;
        p2--;
    }

    return s;
}

int main() {
    const string test = "leetcode";
    cout << reverseVowels2(test) << endl;

    return 0;
}
