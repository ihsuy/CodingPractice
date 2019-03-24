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

*/

void solver(vector<int> students, const int& N, const int& P, const int& case_count)
{
	sort(students.begin(), students.end());

	int result = INT_MAX;

	for(int i = P-1; i < N; ++i)
	{
		int temp = 0;
		for(int j = i-(P-1); j < i; ++j)
		{
			cout <<"ij:" << i << " " << j << endl;
			temp += (students[i]-students[j]);
		}
		if(temp < result)
		{
			result = temp;
		}
	}

	cout << "Case #" << case_count << ": " << result << '\n';
}

int main()
{
	int T;
	cin >> T;

	for(int case_count = 1; case_count <= T; ++case_count)
	{
		int N, P;
		cin >> N >> P;
		vector<int> students;
		students.reserve(N);
		for (int i = 0; i < N; ++i)
		{	// get all booking informations for this test case
			int S;
			cin >> S;
			students.push_back(S);
		}

		// calculate
		solver(students, N, P, case_count);
	}

	return 0;
}

