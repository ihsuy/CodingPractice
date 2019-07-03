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
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes,
only nodes itself may be changed.
*/

void reorderList1(ListNode* head) {
    if (head == nullptr)
        return;

    vector<ListNode*> nodes{head};
    while (head = head->next) {
        nodes.push_back(head);
    }

    for (int i = 0, j = nodes.size() - 1; i < j;) {
        nodes[i]->next = nodes[j];
        nodes[j--]->next = nodes[++i];
    }

    nodes[nodes.size() / 2]->next = nullptr;
}

void reorderList(ListNode* head) {
    if (not head or not head->next or not head->next->next)
        return;

    ListNode *r1, *r2 = r1 = head, *r3, *r4, *r5;
    while (r2 and (r2 = r2->next)) {
        r1 = r1->next;
        r2 = r2->next;
    }
    r3 = r1->next;
    r4 = r3->next;
    while (r4) {
        r5 = r4->next;
        r4->next = r3;
        r3 = r4;
        r4 = r5;
    }
    r1->next = r1->next->next = nullptr;
    while (r3) {
        r2 = head->next;
        r4 = r3->next;
        head->next = r3;
        r3->next = r2;
        r3 = r4;
        head = r2;
    }
}

int main() {
    return 0;
}
