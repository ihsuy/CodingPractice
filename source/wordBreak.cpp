#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
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
inline int two(int n) {
    return 1 << n;
}
inline int test(int n, int b) {
    return (n >> b) & 1;
}
inline void set_bit(int& n, int b) {
    n |= two(b);
}
inline void unset_bit(int& n, int b) {
    n &= ~two(b);
}
inline int last_bit(int n) {
    return n & (-n);
}
inline int ones(int n) {
    int res = 0;
    while (n && ++res)
        n -= n & (-n);
    return res;
}
template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        std::cout << (*i1) << ", ";
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Given a non-empty string s and a dictionary wordDict containing a
list of non-empty words, add spaces in s to construct a sentence where
each word is a valid dictionary word. Return all such possible sentences.

The same word in the dictionary may be reused multiple times in the
segmentation. You may assume the dictionary does not contain duplicate words.
*/

void old_wordBreak_helper(const string& prefix,
                          const string& sentence,
                          const string& s,
                          const int& i,
                          const unordered_set<string>& wordDict,
                          list<string>& result,
                          unordered_map<int, string>& buffer) {
    string new_prefix = prefix + s[i];

    if (i == s.length() - 1) {
        if (wordDict.find(new_prefix) != wordDict.end()) {
            result.push_back(sentence + ((sentence.length() == 0) ? "" : " ") +
                             new_prefix);
        }
        return;
    }

    if (wordDict.find(new_prefix) ==
        wordDict.end()) {  // if the word is NOT found in dictionary, continue
        old_wordBreak_helper(new_prefix, sentence, s, i + 1, wordDict, result,
                             buffer);
    } else {  // if this word appears in the dictionary
        // we have 2 choices, ignore it, or push it to
        // the sentence

        // don't add and continue with it
        old_wordBreak_helper(new_prefix, sentence, s, i + 1, wordDict, result,
                             buffer);

        // add to sentence
        old_wordBreak_helper(
            "", sentence + ((sentence.length() == 0) ? "" : " ") + new_prefix,
            s, i + 1, wordDict, result, buffer);
    }
}

vector<string> old_wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for (auto& item : wordDict) {
        dict.insert(item);
    }

    list<string> result;

    unordered_map<int, string> buffer;

    old_wordBreak_helper("", "", s, 0, dict, result, buffer);

    return vector<string>(result.begin(), result.end());
}

vector<string> helper(string s,
                      vector<string>& wordDict,
                      unordered_map<string, vector<string>>& m) {
    if (m.count(s))
        return m[s];
    if (s.empty())
        return {""};
    vector<string> res;
    for (string word : wordDict) {
        if (s.substr(0, word.size()) != word)
            continue;
        vector<string> rem = helper(s.substr(word.size()), wordDict, m);
        for (string str : rem) {
            res.push_back(word + (str.empty() ? "" : " ") + str);
        }
    }
    return m[s] = res;
}

vector<string> wordBreak3(string s, vector<string>& wordDict) {
    unordered_map<string, vector<string>> m;
    return helper(s, wordDict, m);
}

vector<string> wordBreak_helper(const string& s,
                                const unordered_set<string>& wordDict,
                                unordered_map<string, vector<string>>& buffer) {
    if (buffer.count(s)) {
        return buffer[s];
    }

    if (s.empty()) {
        return {""};
    }

    vector<string> result;

    for (string word : wordDict) {
        string token = s.substr(0, word.size());
        if (word == token) {
            auto remain =
                wordBreak_helper(s.substr(token.size()), wordDict, buffer);
            for (auto& piece : remain) {
                result.push_back(token + ((piece.length() == 0) ? "" : " ") +
                                 piece);
            }
        }
    }

    buffer[s] = result;
    return result;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for (auto& item : wordDict) {
        dict.insert(item);
    }

    unordered_map<string, vector<string>> buffer;

    auto result = wordBreak_helper(s, dict, buffer);

    return result;
}

int main() {
    string s = "pineapplepenapple";
    vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};
    auto result = wordBreak(s, wordDict);

    inspect<vector<string>>(result);
    return 0;
}
