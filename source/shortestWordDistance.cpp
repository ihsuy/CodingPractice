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
Given a list of words and two words word1 and word2,
return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
*/
int shortestDistance(vector<string>& words, string word1, string word2)
{
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < words.size(); ++i)
    {
        string word = words[i];
        if (m.count(word) == 0)
        {
            m.emplace(word, vector<int> {i});
        }
        else
        {
            m[word].push_back(i);
        }
    }
    vector<int>& v1 = m[word1], &v2 = m[word2];
    int dist = INT_MAX;
    for (int i = 0, j = 0; i < v1.size() and j < v2.size();)
    {
        int dif = v1[i] - v2[j];
        if (dif < 0)
        {
            dif = -dif;
            i++;
        }
        else
        {
            j++;
        }
        if (dif == 1)
        {
            return 1;
        }
        if (dif < dist)
        {
            dist = dif;
        }
    }
    return dist;
}

int main()
{


    return 0;
}
