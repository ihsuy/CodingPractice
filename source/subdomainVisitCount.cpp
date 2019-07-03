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
inline void inspect(typename T::iterator i1, typename T::iterator i2) {
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> counter;
    stringstream buffer;

    vector<string> result;

    for (int i = 0; i < cpdomains.size(); ++i) {
        buffer.clear();
        buffer.str(cpdomains[i]);

        int visits;
        buffer >> visits;

        string domains;
        buffer >> domains;
        s while (true) {
            if (counter.find(domains) == counter.end()) {
                counter[domains] = visits;
            } else {
                counter[domains] += visits;
            }

            auto dot_pos = find(domains.begin(), domains.end(), '.');
            if (dot_pos == domains.end()) {
                break;
            }
            domains.erase(domains.begin(),
                          find(domains.begin(), domains.end(), '.') + 1);
        }
    }

    for (auto& item : counter) {
        string msg = to_string(item.second) + " " + item.first;
        result.push_back(msg);
    }

    return result;
}

int main() {
    vector<string> v{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com",
                     "5 wiki.org"};
    auto result = subdomainVisits(v);

    for (std::vector<string>::iterator i = result.begin(); i != result.end();
         ++i) {
        cout << *i << endl;
    }

    return 0;
}
