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
In a forest, each rabbit has some color. Some subset of rabbits
(possibly all of them) tell you how many other rabbits have the
same color as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be
inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into
the array. The smallest possible number of rabbits in the forest is therefore 5:
3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0
*/

int numRabbits(vector<int>& answers) {
    sort(answers.begin(), answers.end());
    answers.push_back(1000);
    int count = 1, result = 0;
    for (int i = 1; i < answers.size(); ++i) {
        if (answers[i] != answers[i - 1]) {
            int base = answers[i - 1] + 1;
            int n = count / base + (count % base > 0 ? 1 : 0);
            result += n * base;
            count = 1;
        } else {
            count++;
        }
    }
    return result;
}

int main() {
    vector<int> n{1, 3, 4};
    cout << numRabbits(n) << endl;

    return 0;
}
