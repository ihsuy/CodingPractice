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

*/

int isMedian(const vector<int>& v1, const vector<int>& v2, const int& i)
{	// for even sized array case:  returns true for  the first median
	int len1 = v1.size(), len2 = v2.size();
	int ltMed = ((len1 + len2) % 2 != 0) ? (len1 + len2) / 2 : (len1 + len2) / 2 - 1;

	int pos2 = ltMed - i - 1; // doubt

	if (pos2 < 0)
	{
		return -1;
	}

	if (pos2 >= v2.size())
	{
		return 1;
	}

	if (v2[pos2] < v1[i] and v2[pos2 + 1] > v1[i])
	{
		return 0;
	}
	else if (v2[pos2 + 1] < v1[i])
	{
		return 1;
	}
	else if (v2[pos2] > v1[i])
	{
		return -1;
	}
}

double findMedian(const vector<int>& v1, const vector<int>& v2)
{
	// search in v1
	int med1 = -1;
	int low = 0, high = v1.size() - 1;
	while (low <= high)
	{

		int mid = (low + high) / 2;
		if (isMedian(v1, v2, mid) < 0)
		{
			high = mid - 1;
		}
		else if (isMedian(v1, v2, mid) == 0)
		{
			med1 = mid;
			break;
		}
		else
		{
			low = mid + 1;
		}
	}
	if (med1 == -1)
	{
		int med2 = -1;
		int low = 0, high = v2.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (isMedian(v2, v1, mid) < 0)
			{
				high = mid - 1;
			}
			else if (isMedian(v2, v1, mid) == 0)
			{
				med1 = mid;
				break;
			}
			else
			{
				low = mid + 1;
			}
		}
		int med = (med1 == -1) ? med2 : med1;
		if ((v1.size() + v2.size()) % 2 != 0)
		{
			return med;
		}
		else
		{
			int ltMed = ((v1.size() + v2.size()) / 2 - 1);
			int med_comp = (ltMed - med + 1);
			auto med_next = ((med1 == -1) ? v2 : v1)[med];
			return (((med_comp > med_next) ? med_comp : med_next) + med) / 2;
		}
	}
	else
	{
		return v1[med1];
	}
}


int main()
{
	vector<int> v1 {3, 5, 7, 9}; 
	vector<int> v2 {4, 8, 10, 12};

	cout << "result: " << findMedian(v1, v2) << '\n';

	return 0;
}
