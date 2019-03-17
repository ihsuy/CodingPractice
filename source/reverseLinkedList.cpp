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

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* linkedList(const vector<int>& v)
{
	if(v.size() == 0)
	{
		return NULL;
	}

	ListNode* head = new ListNode(v[0]);
	ListNode* temp = head;
	for(int i = 1; i < v.size(); ++i)
	{
		temp->next = new ListNode(v[i]);
		temp = temp->next;
	}

	return head;
}

void showll(ListNode* head)
{
	if(head == NULL)
	{
		return;
	}

	while(head != NULL)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << "null\n";
}

ListNode* reverseList(ListNode* head) {
	if(head == NULL)
	{
		return NULL;
	}

	ListNode* r = new ListNode(head->val);

	head = head->next;

	while(head != NULL)
	{
		ListNode* temp = r;
		r = new ListNode(head->val);
		r->next = temp;

		head = head->next;
	}

	return r;
}

ListNode* reverseList_recursive(ListNode* head, ListNode* &rhead) {
	if(head == NULL)
	{
		return NULL;
	}

	ListNode* tmp = new ListNode(head->val);
	ListNode* prev;
	if(head->next != NULL)
	{
		prev = reverseList_recursive(head->next, rhead);
	}
	else
	{
		rhead = new ListNode(head->val);
		return rhead;
	}

	prev->next = tmp;
	return tmp;
}

ListNode* reverseList_recursive2(ListNode* head) {
	if(head == NULL or head->next == NULL)
	{
		return head;
	}

	ListNode* rhead = reverseList_recursive2(head->next);

	// this will first happen when we arrive at the second last node
	// then we want the last node to point to the second last node
	// since the second last node's next is the last node
	// this can be accomplished by making current_node->next->next = current_node
	// then carefully recurse back to the beginning
	head->next->next = head;

	// setting head->next to NULL everytime to avoid the corner case
	// when there're only 2 elements in the list which the result will be
	// a cycled linked list.
	head->next = NULL;

	return rhead;
}

int main()
{
	vector<int> v{1,2,3,4,5,6,7};
	ListNode* l = linkedList(v);

	showll(l);

	ListNode* rl = reverseList(l);

	showll(rl);

	ListNode* rlr = NULL;
	reverseList_recursive(l, rlr);

	showll(rlr);

	ListNode* rlr2 = reverseList_recursive2(l);
	showll(rlr2);
	return 0;
}
