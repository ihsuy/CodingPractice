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
#include <iomanip>
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
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
*/

bool isNumber(string s)
{
	if (s == "")
	{
		return false;
	}
	// remove leading spaces and trailing spaces
	auto front = s.find_first_not_of(" ");

	if (front == string::npos)
	{
		return false;
	}

	auto back = s.find_last_not_of(" ");
	s = s.substr(front, back - front + 1);

	//cout << "front: " << front << " back: " << back << endl;
	//cout << "(" << s << ")"<< endl;

	// check if there's invalid character
	string valid_characters = "0123456789e+-.";
	if (s.find_first_not_of(valid_characters) != string::npos)
	{
		//cout << "bad\n";
		return false;
	}


	vector<int> dot_pos;
	vector<int> e_pos;
	vector<int> minus_pos;
	vector<int> plus_pos;

	// do a series of tests
	bool seenE = false;
	int numCount_before_e = 0;
	int numCount_after_e = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		switch (s[i])
		{
		case '.':
			dot_pos.push_back(i);
			break;
		case 'e':
			seenE = true;
			e_pos.push_back(i);
			break;
		case '-':
			minus_pos.push_back(i);
			break;
		case '+':
			plus_pos.push_back(i);
			break;
		default:
			if (not seenE)
			{
				numCount_before_e ++;
			}

			if (seenE)
			{
				numCount_after_e++;
			}
		}
	}

	// there can be at most 1 '.'
	// there can be at most 1 'e'
	if (dot_pos.size() > 1 or e_pos.size() > 1)
	{
		return false;
	}

	// there's at least one number before e
	if (numCount_before_e == 0)
	{
		return false;
	}

	// if '.' exists
	if (dot_pos.size() != 0)
	{
		// '.' pos must be loacted before 'e' pos
		if (e_pos.size() != 0 and dot_pos[0] > e_pos[0])
		{
			return false;
		}
	}

	// when 'e' exists
	if (e_pos.size() != 0)
	{	// 'e' can't be at the first position or the last position
		if (e_pos[0] == 0 or e_pos[0] == s.length() - 1)
		{
			return false;
		}

		//there can be up to total 2 '-'s and '+'s
		if (plus_pos.size() + minus_pos.size() > 2)
		{
			return false;
		}

		// there can't be more than 1 '-' or '+' before 'e' or after 'e'

		// '+' and '-' if both uniquely exist
		// they must be on different side of 'e'
		if (plus_pos.size() == 1 and minus_pos.size() == 1
		        and ((plus_pos[0] - e_pos[0]) * (minus_pos[0] - e_pos[0]) > 0))
		{
			return false;
		}
		else if (plus_pos.size() == 2
		         and ((plus_pos[0] - e_pos[0]) * (plus_pos[1] - e_pos[0]) > 0))
		{	// if there're 2 '+'s
			// they must be on different sides of 'e'
			return false;
		}
		else if (minus_pos.size() == 2
		         and ((minus_pos[0] - e_pos[0]) * (minus_pos[1] - e_pos[0]) > 0))
		{
			return false;
		}

		// '-' '+' pos must be either the first location or immediently after 'e'
		for (int i = 0; i < minus_pos.size(); ++i)
		{
			if (minus_pos[i] != 0 and minus_pos[i] != e_pos[0] + 1)
			{
				return false;
			}
			// must have at least 1 number following
			if (minus_pos[i] == s.length() - 1)
			{
				return false;
			}
		}
		for (int i = 0; i < plus_pos.size(); ++i)
		{
			if (plus_pos[i] != 0 and plus_pos[i] != e_pos[0] + 1)
			{
				return false;
			}
			// must have at least 1 number following them
			if (plus_pos[i] == s.length() - 1)
			{
				return false;
			}
		}

	}
	else
	{	// when 'e' doesn't exist,
		// there can be only 1 '+' or '-'
		if (plus_pos.size() + minus_pos.size() > 1)
		{
			return false;
		}

		// '+' or '-' if exists
		if (plus_pos.size() != 0 or minus_pos.size() != 0)
		{
			// must be at the first position
			int pos_to_check = (plus_pos.size() != 0) ? plus_pos[0] : minus_pos[0];
			if (pos_to_check != 0)
			{
				return false;
			}

			// must have at least 1 number following it
			if (pos_to_check == s.length() - 1)
			{
				return false;
			}
			if (not isdigit(s[pos_to_check + 1]))
			{
				if (pos_to_check >= s.length() - 2)
				{
					return false;
				}
				if (s[pos_to_check + 1] != '.' or not isdigit(s[pos_to_check + 2]))
				{
					return false;
				}
			}
		}
	}

	return true;
}

int main()
{
	vector<string> test_cases
	{
		"0",
		" 0.1",
		"abc",
		"1 a",
		"2e10",
		"-90e3",
		"1e",
		"e3",
		"6e-1",
		"99e2.5",
		"53.5e93",
		"--6",
		"-+3",
		"95a54e53",
		" ",
		".",
		".e",
		".e1",
		"1.e1",
		"+",
		"-",
		"4e+",
		"e",
		"+.8",
		"+.8e10",
		"+.e10",
		"-e58"
	};
	for (auto& test_case : test_cases)
	{
		cout << left << setw(10) << test_case << ": ";
		cout << (isNumber(test_case) ? "true" : "false") << '\n';
	}

	return 0;
}
