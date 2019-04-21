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
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }

/////////////////////////////////////////////////////////////
using namespace std;

string nextClosestTime(string time)
{
	vector<int> tt(4);
	tt[0] = time[0] - '0';
	tt[1] = time[1] - '0';
	tt[2] = time[3] - '0';
	tt[3] = time[4] - '0';

	vector<int> rank = tt;
	sort(rank.begin(), rank.end());

	vector<int> t = tt;
	t.pop_back();
	sort(t.begin(), t.end());
	for (int i = 0; i < 3; ++i)
	{
		if (t[i] > tt[3])
		{
			time[4] = to_string(t[i])[0];
			return time;
		}
	}

	t = tt;
	t.erase(t.begin() + 2);
	sort(t.begin(), t.end());
	for (int i = 0; i < 3; ++i)
	{
		if ((t[i] < 6 and t[i] > tt[2]))
		{
			time[3] = to_string(t[i])[0];
			time[4] = to_string(rank[0])[0];
			return time;
		}
	}

	t = tt;
	t.erase(t.begin() + 1);
	sort(t.begin(), t.end());
	for (int i = 0; i < 3; ++i)
	{
		if (((tt[0] == 2 and t[i] < 4) or (tt[0] != 2)) and t[i] > tt[1])
		{
			time[1] = to_string(t[i])[0];
			time[3] = to_string(rank[0])[0];
			time[4] = to_string(rank[0])[0];
			return time;
		}
	}

	t = tt;
	t.erase(t.begin());
	sort(t.begin(), t.end());
	for (int i = 0; i < 3; ++i)
	{
		if (t[i] < 2 and t[i] > tt[0])
		{
			time[0] = to_string(t[i])[0];
			time[1] = to_string(rank[0])[0];
			time[3] = to_string(rank[0])[0];
			time[4] = to_string(rank[0])[0];
			return time;
		}
	}


	time[0] = to_string(rank[0])[0];
	time[1] = to_string(rank[0])[0];
	time[3] = to_string(rank[0])[0];
	time[4] = to_string(rank[0])[0];

	return time;
}

int main()
{

	cout << nextClosestTime("13:55");
	return 0;
}
