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


vector<int> rearrangeBarcodes(vector<int>& barcodes)
{
    if (barcodes.size() == 1)
    {
        return barcodes;
    }

    unordered_map<int, int> counter;
    for (auto& item : barcodes)
    {
        if (counter.count(item))
        {
            counter[item]++;
        }
        else
        {
            counter[item] = 1;
        }
    }

    priority_queue<pair<int, int>> pq;
    for(auto& p : counter)
    {
        pq.push({p.second, p.first});
    }
    pair<int, int> prev = {0, 0};
    vector<int> res;
    res.reserve(barcodes.size());
    while(not pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();

        res.push_back(top.second);

        if(prev.first>0)
        {
            pq.push(prev);
        }
        
        top.first--;
        prev = top;
    }
    return res;
}

int main()
{
    vector<int> nums{1,1,1,1,2,2,3,3};
    auto res = rearrangeBarcodes(nums);
    inspect<vector<int>>(res);

    return 0;
}
