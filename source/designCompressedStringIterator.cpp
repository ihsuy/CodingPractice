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
Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/

class StringIterator {
    int pos;
    vector<pair<char, int>> str;
public:
    StringIterator(const string& compressedString) 
    : pos(0) {
        // preprocess 'compressedString', assuming correct input format
        // parse 'compressedString' into vector of pairs of char and int
        // i.e. a3b2 => vector<pair<char, int>> str: {{'a', 3}, {'b', 2}}
        for (int i = 0; i < compressedString.length(); ++i) {
            if (isalpha(compressedString[i])) {
                char ch = compressedString[i];
                string d(1, compressedString[++i]);
                while (isdigit(compressedString[i + 1])) {
                    d += compressedString[++i];
                }
                str.emplace_back(ch, stoi(d));
            }
        }
    }

    char next() {
        if (pos >= str.size()) {
            return ' ';
        } else if (str[pos].second == 0) {
            pos++;
            return next();
        }
        str[pos].second--;
        return str[pos].first;
    }

    bool hasNext() {
        return pos < str.size() && !(pos == str.size() - 1 and str[pos].second == 0);
    }
};

int main()
{


    return 0;
}
