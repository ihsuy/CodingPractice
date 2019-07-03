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
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.



Example 1:

Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer
points to itself.
*/

// recursive
void deepcopy(Node*& head, Node*& cp, unordered_map<Node*, Node*>& copyof) {
    if (not head) {
        return;
    }
    if (copyof.count(head)) {
        cp = copyof[head];
        return;
    }

    cp = new Node(head->val, nullptr, nullptr);
    copyof[head] = cp;
    deepcopy(head->next, cp->next, copyof);
    deepcopy(head->random, cp->random, copyof);
}
Node* copyRandomList(Node* head) {
    if (not head) {
        return nullptr;
    }

    unordered_map<Node*, Node*> copyof;
    Node* cp = nullptr;
    deepcopy(head, cp, copyof);
    return cp;
}

// iterative (hence faster)
Node* copyRandomList(Node* head) {
    if (not head) {
        return nullptr;
    }

    unordered_map<Node*, Node*> copyof;
    auto h = head;
    while (h) {
        copyof[h] = new Node(h->val, nullptr, nullptr);
        h = h->next;
    }
    h = head;
    while (h) {
        copyof[h]->next = copyof[h->next];
        copyof[h]->random = copyof[h->random];
        h = h->next;
    }
    return copyof[head];
}

int main() {
    return 0;
}
