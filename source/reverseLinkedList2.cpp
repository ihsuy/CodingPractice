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
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

void show_linkedList(ListNode* head)
{
	unordered_set<ListNode*> seen;

	while (head != nullptr)
	{
		if (seen.count(head) != 0)
		{
			cout << "loop detected\n";
			return;
		}
		seen.insert(head);
		cout << head->val << "->";
		head = head->next;
	}
	cout << "null\n";
}

ListNode* linkedList(const vector<int>& v)
{
	if (v.size() == 0)
	{
		return nullptr;
	}

	ListNode* head = new ListNode(v[0]);
	auto temp = head;
	for (int i = 1; i < v.size(); ++i)
	{
		temp->next = new ListNode(v[i]);
		temp = temp->next;
	}

	return head;
}

ListNode* reverseBetween(ListNode* head, int m, int n)
{	// Note: m starts from 1 (not 0)
	// and the range is [m, n] inclusive
	ListNode* temp = head;
	// move to m-th position
	for (int i = 1; i < m - 1; ++i)
	{
		head = head->next;
	}


	return temp;
}

int main()
{
	auto mylist = linkedList({1, 2, 3, 4, 5});
	show_linkedList(mylist);
	auto mylist_r = reverseBetween(mylist, 2, 4);
	show_linkedList(mylist_r);
	return 0;
}
