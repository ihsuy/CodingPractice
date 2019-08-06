#include <math.h>
#include <algorithm>
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
#include <vector>
/////////////////////////////////////////////////////////////
using namespace std;

string longestPalindrome(string s) {
    int win_max = s.length();
    int win_min = 2;
    while (win_max >= win_min) {
        for (int i = 0; i <= s.length() - win_max; ++i) {
            int b = i;
            int e = i + win_max - 1;

            while (b < e) {
                if (s[b] != s[e]) {
                    break;
                }
                b++;
                e--;
            }
            if (b >= e) {
                return s.substr(i, win_max);
            }
        }
        win_max--;
    }
    return string(1, s[0]);
}

int main() {
    cout << longestPalindrome("cbbd") << endl;

    return 0;
}
