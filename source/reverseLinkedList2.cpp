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
// create linkedlist from vector
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
	if(head == nullptr)
	{
		return nullptr;
	}
	
	ListNode* temp = head;
	// if m is not 1 move to m-1 th position
	ListNode* end_of_first_part, *end_of_middle_part;
	if (m != 1)
	{	// this process seperate out the part 1(unreversed portion 1)
		for (int i = 1; i < m - 1; ++i)
		{
			head = head->next;
		}
		end_of_first_part = head;
		head = head->next;
	}

	// tail of the middle reversed part
	// since its going to be reversed its 
	// current head should become its tail
	end_of_middle_part = head;
	auto next = head->next;

	// reverse m~n
	for (int i = m; i < n; ++i)
	{
		auto nextnext = next->next;
		next->next = head;
		head = next;
		next = nextnext;
	}

	if (m != 1)
	{	// if m is not 1, part 1 length isn't 0.
		// we then need to connect its end to the 
		// new beginning of the middle reversed portion
		end_of_first_part->next = head;
	}
	else
	{	// if theres no part 1, head now is the 
		// new head of the linkedlist
		temp = head;
	}

	// connect the end of the middle part to part2 
	// (unreversed portion2 if doesnt exist nullptr)
	end_of_middle_part->next = next;

	return temp;
}

int main()
{
	auto mylist = linkedList({1,2,3,4,5,6,7,8});
	show_linkedList(mylist);
	auto mylist_r = reverseBetween(mylist, 1, 8);
	show_linkedList(mylist_r);
	return 0;
}
