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
Given a string, find the first non-repeating character in
it and return it's index. If it doesn't exist, return -1.
*/

int firstUniqChar(const string& s) {  // use list for constant time removal

    list<int> order;
    unordered_map<int, list<int>::iterator> candidates;
    unordered_set<int> ignore;

    for (int i = 0; i < s.length(); ++i) {
        auto cur = s[i];
        if (ignore.count(cur) != 0) {  // skip if cur is in ignore list
            continue;
        }

        if (candidates.count(cur) ==
            0) {  // if first seen, insert into candidate list
            order.push_back(i);
            candidates[cur] = prev(order.end());
        } else {  // have seen this before,
            // remove it from candidate, and add to ignore list
            order.erase(candidates[cur]);
            candidates.erase(cur);
            ignore.insert(cur);
        }
    }

    if (order.size() == 0) {  // no unique character
        return -1;
    }

    return order.front();
}

int firstUniqChar2(const string& s) {  // use list for constant time removal

    unordered_map<char, int> counter;
    for (int i = 0; i < s.length(); ++i) {
        if (counter.count(s[i]) == 0) {
            counter[s[i]] = 1;
        } else {
            counter[s[i]]++;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (counter[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s = "yushiqiu";

    cout << firstUniqChar(s) << endl;
    cout << firstUniqChar2(s) << endl;
    return 0;
}
