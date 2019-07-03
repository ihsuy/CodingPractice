#include <math.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool strLenCmp(const string& s1, const string& s2) {
    return s1.length() < s2.length();
}

void removePrefixDup(vector<string>& v) {
    sort(v.begin(), v.end(), strLenCmp);
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[i] == "" or v[j] == "") {
                continue;
            }

            if (v[i] == v[j].substr(0, v[i].length())) {
                v[j] = "";
            }
        }
    }
}

double calculateWinningSeq(const int& N, const vector<string>& p) {
    double totalPoss = pow(2, N);
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] != "") {
            totalPoss -= pow(2, (N - p[i].length()));
        }
    }
    return totalPoss;
}

int main() {
    int T, N, P;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> P;
        vector<string> prefixes;
        string prefix;
        for (int j = 0; j < P; ++j) {
            cin >> prefix;
            prefixes.push_back(prefix);
        }
        removePrefixDup(prefixes);

        cout << "Case #" << i + 1 << ": " << setprecision(50)
             << calculateWinningSeq(N, prefixes) << endl;
    }
    return 0;
}
