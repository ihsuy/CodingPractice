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

*/

auto comp = [](pair<int, int> p1, pair<int, int> p2) 
{
	return (p1.second - p1.first) < (p2.second - p2.first);
};

void fill_if(vector<int>& v,
             const int& l, const int& r,
             const int& n, const int& k)
{
	for (int i = l; i <= r ; ++i)
	{
		if (v[i] == n)
		{
			v[i] = k;
		}
	}
}

void solver(vector<pair<int, int>> bookings,
            const int& N, const int& Q, const int& case_count)
{
	sort(bookings.begin(), bookings.end(), comp);

	vector<int> seats(N, 0);
	for(int i = 0 ; i < bookings.size(); ++i)
	{
		auto cur_booking = bookings[i];
		fill_if(seats, cur_booking.first, cur_booking.second, 0, i+1);
	}

	unordered_map<int, int> buffer;
	for(int i = 0; i < seats.size(); ++i)
	{
		if(seats[i] == 0) continue;

		buffer[seats[i]]++;
	}

	inspect<vector<int>>(seats);

	int minval = INT_MAX;
	for(int i = 1; i <= bookings.size(); ++i)
	{
		int temp = buffer[i];
		if(minval > temp)
		{
			minval = temp;
		}
	}

	cout << "Case #" << case_count << ": " << minval << '\n';
}

int main()
{
	int T;
	cin >> T;

	for(int case_count = 1; case_count <= T; ++case_count)
	{
		int N, Q;
		cin >> N >> Q;
		vector<pair<int, int>> bookings;
		for (int i = 0; i < Q; ++i)
		{	// get all booking informations for this test case
			int L, R;
			cin >> L >> R;
			bookings.push_back(pair<int, int>(L-1, R-1));
		}

		// calculate
		solver(bookings, N, Q, case_count);
	}

	return 0;
}
