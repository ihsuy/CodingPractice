#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    map<int, int> buffer;

    for (int i = 0; i < nums.size(); ++i) {
        buffer[nums[i]] = 1;
    }

    int minval = 1;
    while (buffer[minval] == 1) {
        minval++;
    }
    return minval;
}

int main() {
    return 0;
}