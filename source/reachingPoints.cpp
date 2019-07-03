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

*/

bool reachingPoints(const int& sx,
                    const int& sy,
                    const int& tx,
                    const int& ty,
                    vector<vector<int>>& buffer) {
    if (sx > tx or sy > ty) {
        return false;
    }
    if (sx == tx and sy == ty) {
        return true;
    }
    if (buffer[sx][sy] != -1 or buffer[sy][sx] != -1) {
        return buffer[sx][sy] != -1 ? buffer[sx][sy] : buffer[sy][sx];
    }
    auto res1 = reachingPoints(sx + sy, sy, tx, ty, buffer),
         res2 = reachingPoints(sx, sx + sy, tx, ty, buffer);
    buffer[sx + sy][sy] = res1;
    buffer[sx][sx + sy] = res2;
    return res1 or res2;
}

bool reachingPoints2(int& sx, int& sy, int& tx, int& ty) {
    while (tx >= sx && ty >= sy) {
        if (tx == ty) {
            break;
        }
        if (tx > ty) {
            if (ty > sy) {
                tx %= ty;
            } else {
                return (tx - sx) % ty == 0;
            }
        } else {
            if (tx > sx) {
                ty %= tx;
            } else {
                return (ty - sy) % tx == 0;
            }
        }
    }
    return (tx == sx && ty == sy);
}

int main() {
    int tx = 100000, ty = 100000;
    vector<vector<int>> buffer(tx + ty, vector<int>(tx + ty, -1));
    cout << reachingPoints(15, 15, tx, ty, buffer) << endl;

    return 0;
}
