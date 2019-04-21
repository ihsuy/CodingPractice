#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;


int numUniqueEmails(vector<string>& emails)
{
	unordered_set<string> uniqueEmails;

	for (int i = 0; i < emails.size(); ++i)
	{
		string::iterator iter = emails[i].begin();
		string washed;
		washed.reserve(emails[i].length());
		bool seenAt = false;
		while (iter != emails[i].end())
		{
			if (seenAt)
			{
				washed += *iter;
			}
			else if (*iter != '.')
			{
				if (*iter == '+')
				{
					while (*iter != '@')
					{
						iter++;
					}
					seenAt = true;
					washed += *iter;
				}
				else
				{
					washed += *iter;
				}
			}
			iter++;
		}
		uniqueEmails.insert(washed);
	}
	for (auto item : uniqueEmails)
	{
		cout << item << endl;
	}
	return uniqueEmails.size();
}

int main()
{
	vector<string> em{
		"test.email+alex@leetcode.com",
		"test.e.mail+bob.cathy@leetcode.com",
		"testemail+david@lee.tcode.com"
	};
	cout << numUniqueEmails(em) << endl;
	return 0;
}