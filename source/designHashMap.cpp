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
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap.

If the value already exists in the HashMap, update the value.

get(key): Returns the value to which the specified key is mapped,
or -1 if this map contains no mapping for the key.

remove(key) : Remove the mapping for the value key if this
map contains the mapping for the key.
*/

class MyHashMap {
   public:
    /** Initialize your data structure here. */

    // very naive implementation assuming the hashmap size is fixed
    // there's no need to handle key collision and such
    int* storage;

    MyHashMap() : storage(new int[1000001]) {}

    /** value will always be non-negative. */
    void put(int key, int value) { storage[key] = value; }

    /** Returns the value to which the specified key is mapped, or -1 if this
     * map contains no mapping for the key */
    int get(int key) { return storage[key]; }

    /** Removes the mapping of the specified value key if this map contains a
     * mapping for the key */
    void remove(int key) { storage[key] = -1; }
};

int main() {
    return 0;
}
