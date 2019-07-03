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

bool hasCycle(ListNode* head) {
    if (head == nullptr or head->next == nullptr) {
        return false;
    }
    ListNode* faster = head->next;
    while (head != faster) {
        if (faster == nullptr or faster->next == nullptr) {
            return false;
        }
        head = head->next;
        faster = faster->next->next;
    }
    return true;
}

bool hasCycle_withHashTable(ListNode* head) {
    unordered_map<ListNode*, bool> buffer;
    while (head != nullptr) {
        if (buffer.find(head) != buffer.end()) {
            return true;
        }
        buffer[head] = true;
        head = head->next;
    }
    return false;
}

int main() {
    return 0;
}
