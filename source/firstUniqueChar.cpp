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
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<typename T>
inline void inspect(T& t){typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given a string, find the first non-repeating character in
it and return it's index. If it doesn't exist, return -1.
*/

int firstUniqChar(const string& s) 
{	// use list for constant time removal

	list<int> order;
	unordered_map<int, list<int>::iterator> tracker; 
	unordered_set<int> ignore;

	for(int i = 0; i < s.length(); ++i)
	{
		auto cur = s[i];
		if(ignore.count(cur) != 0)
		{	// skip if cur is in ignore list
			continue;
		}

		if(tracker.count(cur)==0)
		{	// if first seen, insert into candidate list
			order.push_back(i);
			tracker[cur] = prev(order.end()); 
		}
		else
		{	// have seen this before,
			// remove it from candidate, and add to ignore list
			order.erase(tracker[cur]);
			tracker.erase(cur);
			ignore.insert(cur);
		}
	}

	if(order.size()==0)
	{	// no unique character
		return -1;
	}

	return order.front();
}


int main()
{
	string s = "";

	cout << firstUniqChar(s) << endl;

	return 0;
}
