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
template<typename T>
inline void inspect(T& t){typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Keypad looks like:

1:     2:abc 3:def
4:ghi  5:jkl 6:mno
7:pqrs 8:tuv 9:wxyz
*/

const vector<string> keypad {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
const vector<int> klen {3,3,3,3,3,4,3,4}; // number of possible choice for each item in keypad

bool increment(vector<int>& counter, const vector<int>& index) {
	int carry = 1;
	for (int i = counter.size()-1; i>=0; --i) {
		counter[i]+=carry;
		carry = counter[i]/klen[index[i]];
		counter[i] = counter[i]%klen[index[i]];
		if (carry == 0) {
			return true;
		}
	}
	return carry == 0;
}

vector<string> letterCombinations(const string& digits) {
	if (digits.length()==0) return {};
	// Model this problem as an number incrementation process
	// in other words, represents total number of possible results using a
	// hybrid-non-uniform-nary integer where every digit of the number has a different n-nary
	vector<int> index, counter(digits.length(), 0);
	vector<string> results;
	for (auto& item : digits) {
		index.push_back(item-50);
	}
	int len = digits.length(), upper = keypad[index[0]].length();
	for (;;) {
		string res; res.reserve(len);
		for (auto i = 0; i < counter.size(); ++i) {
			res += keypad[index[i]][counter[i]];
		}
		results.push_back(res);
		if (!increment(counter, index)) {
			break;
		}
	}
	return results;
}

int main()
{
	// test case omitted

	return 0;
}
