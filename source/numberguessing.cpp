#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string ans = "";
        int A, B, N;
        cin >> A >> B >> N;
        A++;
        while (ans != "CORRECT") {
            int midpoint = (B + A) / 2;
            cout << A << " " << B << endl;
            cout << midpoint << endl;
            cin >> ans;
            if (ans == "TOO_BIG") {
                B = midpoint - 1;
            } else if (ans == "TOO_SMALL") {
                A = midpoint + 1;
            } else if (ans == "WRONG_ANSWER") {
                return 0;
            }
        }
    }
    return 0;
}
