#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <list>
#include <chrono>
#include <random>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <bitset>
#include <fstream>
#include <string>

typedef long long ll;
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Think about Zuma Game. You have a row of balls on the table, 
colored red(R), yellow(Y), blue(B), green(G), and white(W). 
You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it 
into the row (including the leftmost place and rightmost place). 
Then, if there is a group of 3 or more balls in the same color 
touching, remove these balls. Keep doing this until no more balls 
can be removed.

Find the minimal balls you have to insert to remove all the balls 
on the table. If you cannot remove all the balls, output -1.

Examples:

Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW 
-> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty 

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> 
RRRB -> B -> B[B] -> BB[B] -> empty 

Note:
You may assume that the initial row of balls on the table 
won’t have any 3 or more consecutive balls with the same color.
The number of balls on the table won't exceed 20, and the 
string represents these balls is called "board" in the input.
The number of balls in your hand won't exceed 5, and the 
string represents these balls is called "hand" in the input.
Both input strings will be non-empty and only contain 
characters 'R','Y','B','G','W'.
*/

int helper(const string& board, unordered_map<char, int>& hand)
{
    if (board.length() == 0)
    {
        return 0;
    }

    set<int> needballs;
    for (int i = 0, count = 0; i < board.length(); ++i)
    {
        count ++;
        if (i == board.length() - 1 or board[i + 1] != board[i])
        {
            if (count == 1)
            {
                if (hand.count(board[i]) and hand[board[i]] >= 2)
                {
                    auto next_hand{hand};
                    next_hand[board[i]] -= 2; // remove 2 from hand
                    if (next_hand[board[i]] <= 0)
                    {
                        next_hand.erase(board[i]);
                    }
                    string next_board{board};
                    next_board.erase(i, 1); // remove 1 from board
                    needballs.insert(helper(next_board, next_hand) + 2);
                }
            }
            else if (count == 2)
            {
                if (hand.count(board[i]) and hand[board[i]] >= 1)
                {
                    auto next_hand{hand};
                    next_hand[board[i]] -= 1; // remove 1 from hand
                    if (next_hand[board[i]] <= 0)
                    {
                        next_hand.erase(board[i]);
                    }
                    string next_board{board};
                    next_board.erase(i - 1, 2); // remove 2 from board
                    needballs.insert(helper(next_board, next_hand) + 1);
                }
            }
            else
            {
                string next_board{board};
                next_board.erase(i - count + 1, count); // remove all consecutive balls from board
                needballs.insert(helper(next_board, hand));
            }
            count = 0;
        }
    }

    return needballs.size()==0?6:*needballs.begin();
}
int findMinStep(string board, string hand) {
    unordered_map<char, int> hd;
    for (auto& ch : hand)
    {
        if (hd.count(ch))
        {
            hd[ch]++;
        }
        else
        {
            hd.emplace(ch, 1);
        }
    }
    auto res = helper(board, hd);
    return res > 5 ? -1 : res;
}

int main()
{
    cout << findMinStep("RWYWRRWRR", "YRY") << endl;

    return 0;
}
