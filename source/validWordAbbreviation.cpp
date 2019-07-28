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
Given a non-empty string s and an abbreviation abbr, return whether the string
matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1",
"w1r1", "1o2", "2r1", "3d", "w3", "4"] Notice that only the above abbreviations
are valid abbreviations of the string "word". Any other string is not a valid
abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase
letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/

// feedNum if receive i which points to a digit, it consumes all consecutive
// digits until an nondigit character is encountered or reach the limit of
// string length. 
// return the number if feedNum successfully detected a valid number
// return 0 if there wasn't a number detected at i
// return -1 if the number was invalid
int feedNum(const string& abbr, int& i, string digit) {
    // by problem definition, first character of a number can't be zero
    if (abbr[i] == '0')
        return -1;
    // try build number
    for (; i < abbr.length() && isdigit(abbr[i]); i++)
        digit += abbr[i];
    // successfully built number?
    return digit.length() ? stoi(digit) : 0;
}

bool validWordAbbreviation(const string& word, const string& abbr) {
    for (int i = 0, j = 0; i < abbr.length(); i++, j++) {
        auto digit = feedNum(abbr, i, "");
        if (digit == -1 || (j += digit) > word.length() || abbr[i] != word[j])
            return false;
    }
    return true;
}

int main() {
    return 0;
}
