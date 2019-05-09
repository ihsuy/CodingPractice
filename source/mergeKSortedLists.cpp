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
Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    set<pair<int, ListNode*>> heap;
    for (int i = 0; i < lists.size(); ++i)
    {
        auto temp = lists[i];
        while (temp)
        {
            heap.insert({temp->val, temp});
            temp = temp->next;
        }
    }

    if (heap.size() == 0)
    {
        return nullptr;
    }

    auto head = heap.begin()->second, tmp = head;
    for (auto t = next(heap.begin()); t != heap.end(); t = next(t))
    {
        tmp->next = t->second;
        tmp = tmp->next;
    }

    return head;
}

int main()
{
    // test code omitted

    return 0;
}
