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

*/

// time O(N) extra space O(1)
void mySwap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
vector<int> findDisappearedNumbers1(vector<int>& nums)
{
    for (int i = 0, j = 1; i < nums.size(); ++i, ++j)
    {
        while (nums[i] != j)
        {
            if (nums[nums[i] - 1] == nums[i])
            {
                break;
            }
            else
            {
                mySwap(nums[i], nums[nums[i] - 1]);
            }
        }
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != i + 1)
        {
            res.push_back(i + 1);
        }
    }
    return res;
}

// time O(N) extra space O(N)
vector<int> findDisappearedNumbers2(vector<int>& nums)
{
    bool m[nums.size() + 1];
    memset(m, false, sizeof(bool) * (nums.size() + 1));
    for (int i = 0; i < nums.size(); ++i)
    {
        m[nums[i]] = true;
    }
    vector<int> res;
    for (int i = 1; i <= nums.size(); ++i)
    {
        if (not m[i])
        {
            res.push_back(i);
        }
    }
    return res;
}

int main()
{


    return 0;
}
