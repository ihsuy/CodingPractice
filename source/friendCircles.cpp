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
There are N students in a class. Some of them are friends, while some are not.
Their friendship is transitive in nature. For example, if A is a direct friend
of B, and B is a direct friend of C, then A is an indirect friend of C. And we
defined a friend circle is a group of students who are direct or indirect
friends.

Given a N*N matrix M representing the friend relationship between students in
the class. If M[i][j] = 1, then the ith and jth students are direct friends with
each other, otherwise not. And you have to output the total number of friend
circles among all the students.

Example 1:
Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend
circle. The 2nd student himself is in a friend circle. So return 2. Example 2:
Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
students are direct friends, so the 0th and 2nd students are indirect friends.
All of them are in the same friend circle, so return 1.
*/

int findCircleNum(vector<vector<int>>& M) {
    // book keeping every visited person in M
    unordered_set<int> visited;
    // n is the total number of person in M and M by definition is a nxn square
    // matrix count will be the result to output
    int count = 0, n = M.size();
    // look for new friend circle until every person is visited
    // everytime when a unvisited person is found, greedily search for all
    // his/her friends and mark them as visite, consequently increase count
    // by 1.
    while (visited.size() != n) {
        for (int i = 0; i < n; ++i) {
            if (!visited.count(i)) {
                count++;
                queue<int> todo;
                todo.push(i);
                visited.insert(i);
                while (!todo.empty()) {
                    int person = todo.front();
                    todo.pop();
                    for (int j = 0; j < n; ++j) {
                        // if person friends j and j isn't visited yet
                        if (M[person][j] && !visited.count(j)) {
                            todo.push(j);
                            visited.insert(j);
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    return 0;
}
