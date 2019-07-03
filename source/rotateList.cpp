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

*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k) {
    if (not head) {
        return head;
    }

    int len = 1;
    ListNode *r1 = head, *r2 = head, *r3 = head;
    while (r1->next) {
        r1 = r1->next;
        len++;
    }

    if (not(k %= len)) {
        return head;
    }

    r1->next = head;
    for (int i = 0; i < len - k; ++i) {
        r3 = r2;
        r2 = r2->next;
    }

    r3->next = nullptr;
    return r2;
}

int main() {
    return 0;
}
