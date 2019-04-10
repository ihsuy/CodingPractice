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
Given a 2D integer matrix M representing the gray scale of an image,
you need to design a smoother to make the gray scale of each cell
becomes the average gray scale (rounding down) of all the 8 surrounding
cells and itself. If a cell has less than 8 surrounding cells, then use
as many as you can.
*/

vector<vector<int>> imageSmoother(vector<vector<int>>& M)
{
	vector<vector<int>> result(M.size(), vector<int>(M[0].size(), 0));

	vector<int> directions{1, 1, -1, -1, 1, 0, -1, 0, 1};

	for (int r = 0; r < M.size(); ++r)
	{
		for (int c = 0; c < M[0].size(); ++c)
		{
			int sum = M[r][c];
			int counter = 1;

			for (int i = 0; i < 8; ++i)
			{
				int next_r = r + directions[i];
				int next_c = c + directions[i + 1];

				if (next_r >= 0 and next_r < M.size() and next_c >= 0 and next_c < M[0].size())
				{
					counter++;
					sum += M[next_r][next_c];
				}
			}

			result[r][c] = sum / counter;
		}
	}

	return result;
}


int main()
{
	vector<vector<int>> m {
		{1, 2, 3, 4},
		{2, 3, 4, 5},
		{3, 4, 5, 6},
		{1, 2, 3, 4}
	};

	auto M = imageSmoother(m);
	cout << "smoothed Image:\n";
	for (auto& line : M)
	{
		inspect<vector<int>>(line);
	}

	return 0;
}

