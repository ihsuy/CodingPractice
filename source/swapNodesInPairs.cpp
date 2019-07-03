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
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes,
only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* nodeSwap(ListNode* head) {
    if (not head or not head->next) {
        return head;
    }
    auto newhead = head->next;
    auto nn = newhead->next;
    newhead->next = head;
    head->next = nodeSwap(nn);
    return newhead;
}
ListNode* swapPairs(ListNode* head) {
    return nodeSwap(head);
}

int main() {
    return 0;
}
