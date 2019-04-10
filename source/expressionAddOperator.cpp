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
inline long long two(long long n) { return 1 << n; }
inline long long test(long long n, long long b) { return (n >> b) & 1; }
inline void set_bit(long long & n, long long b) { n |= two(b); }
inline void unset_bit(long long & n, long long b) { n &= ~two(b); }
inline long long last_bit(long long n) { return n & (-n); }
inline long long ones(long long n) { long long res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given a string that contains only digits 0-9 and a target value,
return all possibilities to add binary operators
(not unary) +, -, or * between the digits so they evaluate to the target value.
*/


// slow
long long op_priority(const string& op)
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
long long evaluate(vector<string> expressions)
{
	if (expressions.size() == 1)
	{
		return stol(expressions[0]);
	}
	vector<string> num;
	vector<string> op;

	for (long long i = 0; i < expressions.size(); ++i)
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
					long long num2 = stol(num.back());
					num.pop_back();
					long long num1 = stol(num.back());
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
		long long num1 = stol(num[num.size() - 2]);
		long long num2 = stol(num.back());
		num.pop_back();
		op.pop_back();
		num[num.size() - 1] = to_string(num1 * num2);
	}

	long long result = stol(num.front());

	if (op.empty())
	{
		return result;
	}

	for (long long i = 1; i < num.size(); ++i)
	{
		string current_op = op[i - 1];
		if (current_op == "+")
		{
			result += stol(num[i]);
		}
		else if (current_op == "-")
		{
			result -= stol(num[i]);
		}
	}
	// inspect<vector<string>>(expressions);
	// inspect<vector<string>>(num);
	// inspect<vector<string>>(op);
	// cout << result << endl;

	return result;
}

void ao_helper(const string& num, const long long& i, const string& expression, vector<string>& inputs, const long long& target, vector<string>& result)
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

	if (inputs[inputs.size() - 1] != "0")
	{
		inputs[inputs.size() - 1] += num[i];
		ao_helper(num, i + 1, expression + num[i], inputs, target, result);
		inputs[inputs.size() - 1].pop_back();
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

// better

class Solution {
public:
    vector<string> addOperators(string num, int target) 
    {    
        vector<string> ans;
        
        if(num.empty())
        {
            return ans;
        }
        
        string expr(num.size()*2, '$');
        
        T = target;
        
        dfs(num, 0, expr, 0, 0, 0, ans);
        
        return ans;
    }
    
    void dfs(const string& S, size_t start, string& expr, size_t expr_len, long long last, long long cur, vector<string>& ans)
    {
        if(start==S.size())
        {
            if(cur == T)
            {
                ans.emplace_back(expr.substr(0, expr_len));
            }
            
            return;
        }
        
        long long val = 0;
        
        auto last_expr_len = expr_len;
        
        if(start != 0)
        {
            ++expr_len; 
        }
        
        for(size_t i = start; i < S.size(); ++i)
        {
            val = val * 10 + (S[i]-'0');
            
            if(S[start] == '0' && (i>start))
            {
                break;
            }
            
            expr[expr_len] = S[i];
            
            ++expr_len;
                        
            if(start==0)
            {
                dfs(S, i+1, expr, expr_len, val, val, ans);
            }
            else
            {
                expr[last_expr_len] = '+';
                dfs(S, i+1, expr, expr_len, val, cur+val, ans);
                expr[last_expr_len] = '-';
                dfs(S, i+1, expr, expr_len, -val, cur-val, ans);
                expr[last_expr_len] = '*';
                dfs(S, i+1, expr, expr_len, val*last, cur-last+val*last, ans);
            }
        }
    }
    long long toLong(const string& s)
    {
        long long num = 0;
        for(auto c: s)
        {
            num = num * 10 + (c-'0');
        }
        
        return num;
    }
    int T;
};

int main()
{
	auto result = addOperators("123321", 6);
	inspect<vector<string>>(result);

	vector<string> expressions {"1", "*", "2", "*", "3"};
	cout << evaluate(expressions) << endl;

	return 0;
}
