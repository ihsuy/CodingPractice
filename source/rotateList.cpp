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

*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* rotateRight(ListNode* head, int k)
{
    if (not head)
    {
        return head;
    }
    
    ListNode* r1 = head, *r2 = head, *r3 = head;
    int len = 1;
    for (; r1->next; r1 = r1->next, len++)
    {
        r1->next = head;
    }

    k %= len;
    for (int i = 0; i < len - k; ++i)
    {
        r3 = r2;
        r2 = r2->next;
    }
    r3->next = nullptr;
    
    return r2;
}

int main()
{


    return 0;
}
