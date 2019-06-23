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
We sampled integers between 0 and 255, and stored the results in an array count:  count[k] is the number of integers we sampled equal to k.

Return the minimum, maximum, mean, median, and mode of the sample respectively, as an array of floating point numbers.  The mode is guaranteed to be unique.

(Recall that the median of a sample is:

The middle element, if the elements of the sample were sorted and the number of elements is odd;
The average of the middle two elements, if the elements of the sample were sorted and the number of elements is even.)
*/

vector<double> sampleStats(vector<int>& count) {
    vector<double> res;
    int i = 0;
    while (i < 256 and count[i] == 0)
    {
        i++;
    }
    res.push_back(i);

    long long s = 0, last = 0, mode = 0, modeval = 0, occur = 0;
    for (; i < 256; ++i)
    {
        s += i * count[i];
        if (count[i]) last = i;
        if (count[i] > modeval) {
            modeval = count[i];
            mode = i;
        }
        occur += count[i];
    }
    res.push_back(last);
    res.push_back(double(s) / double(occur));

    if (occur % 2 == 0)
    {
        int m = occur / 2;
        int p = 0, j = 0;
        for (; p < m; ++j)
        {
            p += count[j];
        }
        if (p == m)
        {
            int m1 = j - 1;
            while (count[j] == 0) j++;
            cout << m1 << " " << j << endl;
            res.push_back(double(m1 + j) / 2.0);
        }
        else
        {
            res.push_back(double(j - 1));
        }
    }
    else
    {
        int m = occur / 2 + 1;
        int p = 0, j = 0;
        for (; p < m; ++j)
        {
            p += count[j];
        }
        res.push_back(double(j - 1));
    }

    res.push_back(mode);
    return res;
}

int main()
{


    return 0;
}
