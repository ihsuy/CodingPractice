#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isValid(string s) {
    stack<char> buffer;
    for (int i = 0; i < s.length(); ++i) {
        if (buffer.size() == 0 and
            (s[i] == ')' or s[i] == ']' or s[i] == '}')) {
            return false;
        }
        if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
            buffer.push(s[i]);
        } else if (s[i] == ')' and buffer.top() == '(') {
            buffer.pop();
        } else if (buffer.top() == s[i] - 2) {
            buffer.pop();
        } else {
            return false;
        }
    }
    return !buffer.size();
}

int main() {
    while (1) {
        string inp;
        cin >> inp;

        cout << isValid(inp) << endl;
    }
    return 0;
}