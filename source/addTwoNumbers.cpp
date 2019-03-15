#include<iostream>


using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void appendToEnd(ListNode* head, const int& val)
{
	auto temp_head = head;
	while (temp_head->next != nullptr)
	{
		temp_head = temp_head->next;
	}
	temp_head->next = new ListNode(val);
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *temp1 = l1, *temp2 = l2;

	int len1 = 0, len2 = 0;

	while (temp1 != nullptr)
	{
		len1++;
		temp1 = temp1->next;
	}

	while (temp2 != nullptr)
	{
		len2++;
		temp2 = temp2->next;
	}

	if (len1 > len2)
	{
		temp1 = l1;
		temp2 = l2;
	}
	else
	{
		auto temp = len1;
		len1 = len2;
		len2 = temp;

		temp1 = l2;
		temp2 = l1;
	}

	// temp1 is longer temp2 is shorter
	ListNode* result = nullptr;

	int carry = 0;
	int partial_sum = 0;

	while (temp2 != nullptr)
	{
		// temp step, doesn't decide paritial sum's final value
		partial_sum = temp1->val + temp2->val + carry;

		// final values
		carry = partial_sum / 10;
		partial_sum %= 10;

		if (result == nullptr)
		{	// creating the head of the list
			result = new ListNode(partial_sum);
		}
		else
		{
			appendToEnd(result, partial_sum);
		}

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	if (len1 == len2 and carry != 0)
	{
		appendToEnd(result, carry);
	}
	else if (len1 > len2)
	{
		while (temp1 != nullptr)
		{
			partial_sum = temp1->val + carry;

			// final values
			carry = partial_sum / 10;
			partial_sum %= 10;

			appendToEnd(result, partial_sum);

			temp1 = temp1->next;
		}
		if(carry != 0)
		{
			appendToEnd(result, carry);
		}
	}

	return result;
}

void showll(ListNode* head)
{
	auto temp = head;
	while(temp != nullptr)
	{
		cout << temp->val << "->";
		temp = temp->next;
	}
	cout << "null" << endl;
}

int chtoi(const char& c)
{
	return c-'0';
}

ListNode* itoll(const string& num)
{
	ListNode* result;
	ListNode* temp;
	for(int i = num.length()-1; i >= 0; --i)
	{
		if(i == num.length()-1)
		{
			result = new ListNode(chtoi(num[i]));
			temp = result;
		}
		else
		{
			temp->next = new ListNode(chtoi(num[i]));
			temp = temp->next;
		}
	}

	return result;
}

int main()
{	
	const string n1 = "9999999999";
	const string n2 = "314159261478923";

	ListNode* l1 = itoll(n1);
	ListNode* l2 = itoll(n2);

	showll(l1);
	showll(l2);

	cout << "adding..." << endl;

	ListNode* l3 = addTwoNumbers(l1, l2);

	showll(l3);


	return 0;
}