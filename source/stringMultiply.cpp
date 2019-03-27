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
Given two non-negative integers num1 and num2
represented as strings, return the product of num1 and num2,
also represented as a string.
*/

int chtoi(char ch)
{
	return ch - '0';
}

char itoch(int n)
{
	return n + '0';
}

string addstr(const string& n1, const string& n2)
{
	int len1 = n1.length(), len2 = n2.length();

	string result;
	result.reserve(len1 > len2 ? len1 + 1 : len2 + 1);

	int carry = 0;

	int p1 = len1 - 1, p2 = len2 - 1;
	int res = 0;
	while (p1 >= 0 and p2 >= 0)
	{
		res = chtoi(n1[p1]) + chtoi(n2[p2]) + carry;

		carry = res / 10;

		res = res % 10;

		result += itoch(res);

		p1--;
		p2--;
	}

	if (carry == 0)
	{
		reverse(result.begin(), result.end());

		if (p1 < 0 and p2 >= 0)
		{
			result.insert(result.begin(), n2.begin(), n2.begin() + p2 + 1);
		}
		else if (p1 >= 0 and p2 < 0)
		{
			result.insert(result.begin(), n1.begin(), n1.begin() + p1 + 1);
		}
	}
	else
	{
		if (p1 < 0)
		{
			while (p2 >= 0)
			{
				res = chtoi(n2[p2]) + carry;

				carry = res / 10;

				res = res % 10;

				result += itoch(res);

				p2--;
			}
		}
		else if (p2 < 0)
		{
			while (p1 >= 0)
			{
				res = chtoi(n1[p1]) + carry;

				carry = res / 10;

				res = res % 10;

				result += itoch(res);

				p1--;
			}
		}
		reverse(result.begin(), result.end());
	}
	if (carry != 0)
	{
		result.insert(result.begin(), '1');
	}

	return result;
}

string str_mul_char(string n, char c)
{
	int len = n.length();

	string result;
	result.reserve(len + 1);

	int p = len - 1;
	int carry = 0, res = 0;
	while(p >= 0)
	{
		res = chtoi(c)*chtoi(n[p]) + carry;

		carry = res/10;

		res = res%10;

		result += itoch(res);

		p--;
	}

	if(carry != 0)
	{
		result += itoch(carry);
	}

	reverse(result.begin(), result.end());

	return result;
}

string multiply_helper(const string& num1, const string& num2, const int& len1, const int& len2)
{
	string result;
	result.reserve(len1+len2);
	result = "0";

	string zeros;
	zeros.reserve(len2+1);

	for(int i = len2-1; i >= 0; --i)
	{
		result = addstr(result, str_mul_char(num1, num2[i])+zeros);
		zeros += '0';
	}

	return result;
}

string multiply(const string& num1, const string& num2)
{
	if(num1 == "0" or num2 == "0")
	{
		return "0";
	}

	int len1 = num1.length(), len2 = num2.length();

	if(len1>=len2)
	{
		return multiply_helper(num1, num2, len1, len2);
	}
	else
	{
		return multiply_helper(num2, num1, len2, len1);
	}
}

int main()
{
	const string n1 = "1110239013784973489251284110239013784973489251284110239013784973489251284110239013784973489251284110239013784973489251284110239013784973489251284";
	const string n2 = "12349123121231102390137849734892512841102390137849734892512841102390137849734892512841102390137849734892512848918";
	//string n1 = "0";
	// string n2 = "1";
	cout << multiply(n1, n2) << endl;

	// const char c = '9';

	// cout << addstr(n1, n2) << '\n';
	// cout << str_mul_char(n1, c) << '\n';
	return 0;
}
