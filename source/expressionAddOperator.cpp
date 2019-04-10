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
Given a string that contains only digits 0-9 and a target value,
return all possibilities to add binary operators
(not unary) +, -, or * between the digits so they evaluate to the target value.
*/


// incorrect
int op_priority(const string& op)
{
	if (op == "+" or op == "-")
	{
		return 0;
	}
	else if (op == "*")
	{
		return 1;
	}
	else
	{
		throw runtime_error("invalid operator.");
	}
}
int evaluate(vector<string> expressions)
{
	vector<string> num;
	vector<string> op;

	for (int i = 0; i < expressions.size(); ++i)
	{
		if (i % 2 == 0)
		{
			num.push_back(expressions[i]);
		}
		else
		{
			if (op.empty())
			{
				op.push_back(expressions[i]);
			}
			else
			{
				if (op_priority(op.back()) >= op_priority(expressions[i]))
				{
					int num2 = stoi(num.back());
					num.pop_back();
					int num1 = stoi(num.back());
					num.pop_back();
					string current_op = op.back();
					op.pop_back();

					if (current_op == "+")
					{
						num1 += num2;
					}
					else if (current_op == "-")
					{
						num1 -= num2;
					}
					else if (current_op == "*")
					{
						num1 *= num2;
					}
					//cout << "num1: " << num1 << endl;
					num.push_back(to_string(num1));
					op.push_back(expressions[i]);
				}
				else
				{
					op.push_back(expressions[i]);
				}
			}
		}
	}

	if (op.back() == "*")
	{
		int num1 = stoi(num[num.size()-2]);
		int num2 = stoi(num.back());
		num.pop_back();
		op.pop_back();
		num[num.size()-1] = to_string(num1 * num2);
	}

	int result = stoi(num.front());

	if (op.empty())
	{
		return result;
	}

	for (int i = 1; i < num.size(); ++i)
	{
		string current_op = op[i - 1];
		if (current_op == "+")
		{
			result += stoi(num[i]);
		}
		else if (current_op == "-")
		{
			result -= stoi(num[i]);
		}
	}
	// inspect<vector<string>>(expressions);
	// inspect<vector<string>>(num);
	// inspect<vector<string>>(op);
	// cout << result << endl;

	return result;
}

void ao_helper(const string& num, const int& i, const string& expression, vector<string>& inputs, const int& target, vector<string>& result)
{
	//cout << expression << endl;
	if (i == num.length() and evaluate(inputs) == target)
	{
		result.push_back(expression);
		return;
	}
	else if (i == num.length())
	{
		return;
	}

	inputs.push_back("+");
	inputs.push_back(string(1, num[i]));
	ao_helper(num, i + 1, expression + "+" + num[i], inputs, target, result);
	inputs.pop_back();
	inputs.pop_back();
	inputs.push_back("-");
	inputs.push_back(string(1, num[i]));
	ao_helper(num, i + 1, expression + "-" + num[i], inputs, target, result);
	inputs.pop_back();
	inputs.pop_back();
	inputs.push_back("*");
	inputs.push_back(string(1, num[i]));
	ao_helper(num, i + 1, expression + "*" + num[i], inputs, target, result);
	inputs.pop_back();
	inputs.pop_back();
}
vector<string> addOperators(string num, int target) 
{
	if (num.length() == 0)
	{
		return vector<string>();
	}
	else if (num.length() == 1)
	{
		return (num[0] - '0' == target) ? vector<string> {num} : vector<string> {};
	}

	vector<string> result;
	vector<string> inputs{string(1, num[0])};
	ao_helper(num, 1, string(1, num[0]), inputs, target, result);
	return result;
}

int main()
{
	auto result = addOperators("123", 6);
	inspect<vector<string>>(result);

	vector<string> expressions {"1", "*", "2", "*", "3"};
	cout << evaluate(expressions) << endl;

	return 0;
}
