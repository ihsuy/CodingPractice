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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/



struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) 
{	// there are 2 big cases to handle

	// case 1: when the linkedlist begin with "val"
	// case 2: linkedlist doesn't begin with "val"
	// we solve case 1 first by removing those values
	// then we will be left with case 2 if there's anymore element left

	// case 1
	while (head != nullptr and head->val == val)
	{	// delete head while moving forwared
		auto hn = head->next;
		delete head;
		head = hn;
	}
	if (head == nullptr)
	{	// no more element? return emptry linkedlist
		return nullptr;
	}

	// case 2
	// now head->val is not val
	// we memorize where our head is since its gonna be unchanged
	auto temp = head;
	while (head->next != nullptr)
	{	// go ahead until we reach the end
		while (head->next != nullptr and (head->next->val != val))
		{	// go ahead until we reach the end or find val
			head = head->next;
		}
		// violation of which case cased the loop above to break?

		// we reach at the end, algorithm terminates
		if (head->next == nullptr)
		{	
			break;
		}

		// we find val, remove this node and proceed
		auto nextnext = head->next->next;
		delete head->next;
		head->next = nextnext;
	}

	return temp;
}
int main()
{
	ListNode* ll = new ListNode(1);
	ll->next = new ListNode(2);
	ll->next->next = new ListNode(3);
	ll->next->next->next = new ListNode(2);
	ll->next->next->next->next = new ListNode(1);
	auto result_ll = removeElements(ll, 1);

	// remove all 1s from ll  : 1->2->3->2->1->null
	// result should look like: 2->3->2->null

	while(result_ll != nullptr)
	{
		cout << result_ll->val << "->";
		result_ll = result_ll->next;
	}
	cout << "null\n";

	return 0;
}
