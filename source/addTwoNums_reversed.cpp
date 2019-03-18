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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(typename T::iterator i1, typename T::iterator i2) {while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse_ll(ListNode* l)
{
	ListNode* head = nullptr;

	while(l != nullptr)
	{
		ListNode* temp = new ListNode(l->val);
		temp->next = head;
		head = temp;

		l = l->next;
	}

	return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	l1 = reverse_ll(l1);
	l2 = reverse_ll(l2);

	ListNode* l3 = new ListNode(-1);
	ListNode* temp = l3;

	int carry = 0;

	while(l1 != nullptr and l2 != nullptr)
	{
		int val = l1->val + l2->val + carry;

		carry = val/10;
		val %= 10;

		l3->next = new ListNode(val);
		l3 = l3->next;

		l1 = l1->next;
		l2 = l2->next;
	}

	ListNode* extra = (l1 == nullptr) ? l2: l1;
	if(carry != 0)
	{
		while(extra != nullptr)
		{
			int val = extra->val + carry;

			carry = val/10;
			val %= 10;

			l3->next = new ListNode(val);
			l3 = l3->next;

			extra = extra->next;
		}
		if(carry != 0)
		{
			l3->next = new ListNode(1);
		}
	}
	else
	{
		l3->next = extra;
	}

	l3 = temp->next;

	return reverse_ll(l3);
}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	head = reverse_ll(head);

	while(head != nullptr)
	{
		cout << (head->val) << "->";
		head = head->next;
	}
	cout << "null\n";
	return 0;
}
