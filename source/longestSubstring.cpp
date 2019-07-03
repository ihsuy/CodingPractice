#include <iostream>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> buffer;
    int result = 0, count = 0, checkPoint = -1;

    for (int i = 0; i < s.length(); ++i) {
        int index = (buffer.find(s[i]) == buffer.end()) ? -1 : buffer[s[i]];

        if (checkPoint == -1 and index == -1) {
            count = i + 1;
        } else if (index == -1 or index < checkPoint) {
            count = i - checkPoint;
        } else if (index > checkPoint) {
            checkPoint = index;
            count = i - checkPoint;
        }

        if (count > result) {
            result = count;
        }

        buffer[s[i]] = i;
    }

    return result;
}

int main() {
    cout << lengthOfLongestSubstring("aab") << '\n';

    int i = 10;
    cout << i / 3.0 << endl;
    return 0;
}