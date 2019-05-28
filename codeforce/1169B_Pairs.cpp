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

bool notInPair (const pair<int, int>& p, const int& val)
{
    return p.first != val and p.second != val;
}

bool validPairs(const vector<pair<int, int>>& pairs)
{
    int v1 = pairs[0].first, v11 = 0, v12 = 0,
        v2 = pairs[0].second, v21 = 0, v22 = 0;
    for (int i = 0; i < pairs.size(); ++i)
    {
        if (v11 == 0 and notInPair(pairs[i], v1))
        {
            v11 = pairs[i].first;
            v12 = pairs[i].second;
        }
        if (v21 == 0 and notInPair(pairs[i], v2))
        {
            v21 = pairs[i].first;
            v22 = pairs[i].second;
        }
        if (v11 and v21)
        {
            break;
        }
    }

    bool b11, b12, b21, b22 = b21 = b12 = b11 = true;
    for (int i = 0; i < pairs.size(); ++i)
    {
        if ((b11 or b12) and notInPair(pairs[i], v1))
        {
            if (notInPair(pairs[i], v11))
            {
                b11 = false;
            }
            if (notInPair(pairs[i], v12))
            {
                b12 = false;
            }
        }
        if ((b21 or b22) and notInPair(pairs[i], v2))
        {
            if (notInPair(pairs[i], v21))
            {
                b21 = false;
            }
            if (notInPair(pairs[i], v22))
            {
                b22 = false;
            }
        }

        if (not(b11 or b12 or b21 or b22))
        {
            return false;
        }
    }
    printf("%d %d %d %d", b11, b12, b21, b22);
    return true;
}

vector<pair<int, int>> createTestCase(const int& n /*inclusive value upper bound*/,
                                      const int& m /*number of pairs*/)
{
    vector<pair<int, int>> test_case;
    test_case.reserve(m);
    int mod = n + 1;
    for (int i = 0; i < m; ++i)
    {
        test_case.push_back({rand() % mod, rand() % mod});
    }
    return test_case;
}

vector<pair<int, int>> createCorrectTestCase(const int& n, const int& m,
                    const pair<int, int>& p)
{
    vector<pair<int, int>> test_case;
    test_case.reserve(m);
    int mod = n + 1;
    for (int i = 0; i < m; ++i)
    {
        int pos = rand() % 2, choice = rand() % 2, val = rand() % mod;
        if (pos == 0)
        {
            test_case.push_back({(choice) ? p.first : p.second, val});
        }
        else
        {
            test_case.push_back({val, (choice) ? p.first : p.second});
        }
    }
    return test_case;
}

int main()
{
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    //auto test_case = createTestCase(300000, 300000);
    auto ctest_case = createCorrectTestCase(300000, 300000, {93074, 178990});
    // for (int i = 0; i < ctest_case.size(); ++i)
    // {
    //     cout << ctest_case[i].first << ", " << ctest_case[i].second << endl;
    // }

    auto res = validPairs(ctest_case);
    cout << '\n' << ((res) ? "YES" : "NO") << endl;

    return 0;
}
