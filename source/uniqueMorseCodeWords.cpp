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
International Morse Code defines a standard encoding where each letter is mapped
to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to
"-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is
given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the
Morse code of each letter. For example, "cba" can be written as "-.-..--...",
(which is the concatenation "-.-." + "-..." + ".-"). We'll call such a
concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation:
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
*/
vector<string> dict{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                    "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                    "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                    "...-", ".--",  "-..-", "-.--", "--.."};
int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> uniq;
    for (auto& word : words) {
        string code;
        for (auto& ch : word) {
            code += dict[ch - 'a'];
        }
        uniq.insert(code);
    }
    return uniq.size();
}

int main() {
    return 0;
}
