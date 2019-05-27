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
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.



Example 1:

Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:

Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1]


Note:

1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000

*/

struct Key
{
    int freq; 
    int ch;

    bool operator<(const Key &k) const
    {
        return freq < k.freq;
    }
};

vector<int> rearrangeBarcodes(vector<int>& barcodes)
{
    if (barcodes.size() == 1)
    {
        return barcodes;
    }
    int n = barcodes.size();

    map<int, int> counter;
    for (int i = 0; i < barcodes.size(); ++i)
    {
        if (counter.count(barcodes[i]))
        {
            counter[barcodes[i]]++;
        }
        else
        {
            counter[barcodes[i]] = 1;
        }
    }

    priority_queue< Key > pq;

    for (auto& item : counter)
    {
        pq.push(Key{item.second, item.first});
    }

    vector<int> res;

    Key prev { -1, 0} ;

    while (!pq.empty())
    {
        Key k = pq.top();
        pq.pop();
        res.push_back(k.ch);

        if (prev.freq > 0)
            pq.push(prev);

        (k.freq)--;
        prev = k;
    }

    if (n != barcodes.size())
        return barcodes;

    return res;
}

int main()
{


    return 0;
}
