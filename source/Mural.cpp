#include <iostream>
#include <string>

using namespace std;

int chtoi(const char& ch) {
    return ch - '0';
}

int muralScore(const string& wall, const int& N) {
    int muralWidth = (N + 1) / 2;

    int max_score = 0;

    for (int i = 0; i < muralWidth; ++i) {
        max_score += chtoi(wall[i]);
    }

    int temp_score = max_score;
    cout << temp_score << endl;
    for (int i = 1; i < N - muralWidth + 1; ++i) {
        temp_score += (chtoi(wall[i + muralWidth - 1]) - chtoi(wall[i - 1]));
        if (temp_score > max_score) {
            max_score = temp_score;
        }
        cout << temp_score << endl;
    }

    return max_score;
}
int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        string wall;
        cin >> wall;
        cout << "Case #" << i + 1 << ": " << muralScore(wall, N) << endl;
    }
    return 0;
}
