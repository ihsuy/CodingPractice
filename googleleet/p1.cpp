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
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<typename T>
inline void inspect(typename T::iterator i1, typename T::iterator i2) {while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) 
{
	const string chIgnore = "!?',;.";
	// do washing
	for(int i = 0; i < paragraph.length(); ++i)
	{
		char* ch = &paragraph[i];
		if(isupper(*ch))
		{
			*ch = tolower(*ch);
		}
		else if(*ch != ' ' and not islower(*ch))
		{	// punctuation
			*ch = ' ';
		}
	}
	
	map<string, int> counter;
	stringstream buffer(paragraph);
	string token;
	while(buffer >> token)
	{
		if(find(banned.begin(), banned.end(), token) == banned.end())
		{
			counter[token]++;
		}
	}

	pair<string, int> result = {"", 0};
	for(auto& item : counter)
	{
		if(item.second > result.second)
		{
			result = item;
		}
	}

	return result.first;
}

int main()
{
	vector<string> ban{"hit"};
	string p = "Bob hit a ball, the hit BALL flew far after it was hit.";
	cout << mostCommonWord(p, ban) << endl;
	return 0;
}
