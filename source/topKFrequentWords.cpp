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
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words
have the same frequency, then the word with the lower alphabetical order comes
first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"],
k = 4 Output: ["the", "is", "sunny", "day"] Explanation: "the", "is", "sunny"
and "day" are the four most frequent words, with the number of occurrence being
4, 3, 2 and 1 respectively. Note: You may assume k is always valid, 1 ≤ k ≤
number of unique elements. Input words contain only lowercase letters. Follow
up: Try to solve it in O(n log k) time and O(n) extra space.
*/

struct comp {
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
        if (p1.second != p2.second) {
            return p1.second < p2.second;
        } else {
            return p1.first > p2.first;
        }
    }
};

vector<string> topKFrequent(const vector<string>& words, int k) {
	// count occurence of each words and store the <string, int> pair in a vector
    unordered_map<string, int> counter;
    for (auto& word : words) {
        if (counter.count(word)) {
            counter[word]++;
        } else {
            counter[word] = 1;
        }
    }
    vector<pair<string, int>> p;
    p.reserve(counter.size());
    for (auto& item : counter) {
        p.push_back(item);
    }
	// use heap to retrieve max value defined by custom comparator
	// for k times
    make_heap(p.begin(), p.end(), comp());
    vector<string> result;
    result.reserve(k);
    for (int i = 0; i < k; ++i) {
        result.push_back(p.front().first);
        pop_heap(p.begin(), p.end(), comp());
        p.pop_back();
    }
    return result;
}

int main() {
    return 0;
}
