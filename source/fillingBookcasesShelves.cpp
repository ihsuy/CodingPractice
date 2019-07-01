#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

/*
We have a sequence of books: the i-th book has thickness books[i][0] and height
books[i][1].

We want to place these books in order onto bookcase shelves that have total
width shelf_width.

We choose some of the books to place on this shelf (such that the sum of their
thickness is <= shelf_width), then build another level of shelf of the bookcase
so that the total height of the bookcase has increased by the maximum height of
the books we just put down.  We repeat this process until there are no more
books to place.

Note again that at each step of the above process, the order of the books we
place is the same order as the given sequence of books.  For example, if we have
an ordered list of 5 books, we might place the first and second book onto the
first shelf, the third book on the second shelf, and the fourth and fifth book
on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing
shelves in this manner.

Example:
Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.
*/

vector<vector<int>> buffer{vector<vector<int>>(1001, vector<int>(1001, -1))};
int search(vector<vector<int>>& books,
           const int& width,
           const int& i,
           const int& maxh,
           const int& w) {
    if (i == books.size()) {
        return maxh;
    }
    if (buffer[i][w] != -1) {
        return buffer[i][w];
    }
    auto res1 = maxh + search(books, width, i + 1, books[i][1], books[i][0]);
    auto res2 = (w + books[i][0] > width)
                    ? INT_MAX
                    : search(books, width, i + 1, max(maxh, books[i][1]),
                             w + books[i][0]);
    buffer[i][w] = min(res1, res2);
    return buffer[i][w];
}
int minHeightShelves(vector<vector<int>>& books, int width) {
    return search(books, width, 0, 0, 0);
}

int main() {
    return 0;
}
