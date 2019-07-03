#include <iostream>
#include <string>
#include <vector>
using namespace std;

string licenseKeyFormatting(string S, int K) {
    string s2;
    s2.reserve(S.size());
    for (int i = 0; i < S.length(); ++i) {
        char cur = S[i];
        if (islower(cur) and cur != '-') {
            s2 += toupper(cur);
        } else if (cur != '-') {
            s2 += cur;
        }
    }
    if (s2.length() == 0) {
        return "";
    }

    int head_len = (s2.length() % K == 0) ? K : (s2.length() % K);
    string head;
    int i = 0;
    for (; i < head_len; ++i) {
        head += s2[i];
    }
    if (head_len < s2.length()) {
        head += "-";
    }

    string tail;
    tail.reserve(s2.length());
    int count = 0;
    for (; i < s2.length(); ++i) {
        tail += s2[i];

        count++;

        if (count % K == 0 and i != s2.length() - 1) {
            tail += "-";
        }
    }

    return head + tail;
}

int main() {
    const string s = "a-----a";
    const int k = 2;

    cout << licenseKeyFormatting(s, k);

    return 0;
}