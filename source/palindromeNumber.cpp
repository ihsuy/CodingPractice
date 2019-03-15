#include <iostream>

using namespace std;

bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }
        else if(x < 10)
        {
            return true;
        }
        int x_reversed = 0;
        int x_temp = x;
        for(;x_temp; x_temp /= 10)
        {
            x_reversed = x_reversed*10 + x_temp%10;
        }
        return (x == x_reversed);
    }

int main()
{
	cout << isPalindrome(11) << '\n';
	return 0;
}