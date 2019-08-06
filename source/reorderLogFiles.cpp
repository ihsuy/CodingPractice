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
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
*/

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<pair<string, string>> letterLog;
    vector<string> digitLog, res;
    res.reserve(logs.size());
    for (auto i = 0; i < logs.size(); ++i) {
        int j = 0;
        for (; logs[i][j] != ' '; ++j)
            ;
        if (isdigit(logs[i][j + 1])) {
            digitLog.emplace_back(logs[i]);
        } else {
			// split id and body in advance to avoid repeated operations
            auto pos = logs[i].find(" ");
            letterLog.emplace_back(logs[i].substr(0, pos),
                                   logs[i].substr(pos + 1));
        }
    }
    sort(letterLog.begin(), letterLog.end(),
         [](const pair<string, string>& s1, const pair<string, string>& s2) {
             if (s1.second != s2.second) {
                 return s1.second < s2.second;
             } else {
                 return s1.first < s2.first;
             }
         });
    for (auto& item : letterLog) {
        res.emplace_back(item.first + ' ' + item.second);
    }
    copy(digitLog.begin(), digitLog.end(), back_inserter(res));
    return res;
}

int main() {
    return 0;
}
