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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* linkedList(const vector<int>& v) {
    if (v.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;
    for (int i = 1; i < v.size(); ++i) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }

    return head;
}

void showll(ListNode* head) {
    if (head == nullptr) {
        return;
    }

    while (head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "null\n";
}

ListNode* mergeTwoLists_silly(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    }

    ListNode* head = nullptr;
    ListNode* cur = nullptr;

    while (l1 != nullptr or l2 != nullptr) {
        if (l1 != nullptr and l2 != nullptr and (l1->val <= l2->val)) {
            if (head == nullptr) {
                head = new ListNode(l1->val);
                cur = head;
            } else {
                cur->next = new ListNode(l1->val);
                cur = cur->next;
            }
            l1 = l1->next;
        } else if (l1 != nullptr and l2 != nullptr and (l1->val > l2->val)) {
            if (head == nullptr) {
                head = new ListNode(l2->val);
                cur = head;
            } else {
                cur->next = new ListNode(l2->val);
                cur = cur->next;
            }
            l2 = l2->next;
        } else if (l1 != nullptr and l2 == nullptr) {
            cur->next = new ListNode(l1->val);
            cur = cur->next;

            l1 = l1->next;
        } else if (l1 == nullptr and l2 != nullptr) {
            cur->next = new ListNode(l2->val);
            cur = cur->next;

            l2 = l2->next;
        }
    }

    return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    ListNode* head = result;

    while (l1 != nullptr and l2 != nullptr) {
        if (l1->val <= l2->val) {
            head->next = new ListNode(l1->val);
            l1 = l1->next;
        } else {
            head->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        head = head->next;
    }

    head->next = (l1 == nullptr) ? l2 : l1;
    ;
    return result->next;
}

int main() {
    vector<int> v1 = {1, 2, 5, 6, 8};
    vector<int> v2 = {1, 3, 5, 9};

    auto l1 = linkedList(v1);
    auto l2 = linkedList(v2);

    showll(l1);
    showll(l2);

    auto l3 = mergeTwoLists(l1, l2);

    showll(l3);

    return 0;
}
