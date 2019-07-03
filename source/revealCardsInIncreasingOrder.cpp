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
In a deck of cards, every card has a unique integer.  You can order the deck in
any order you want.

Initially, all the cards start face down (unrevealed) in one deck.

Now, you do the following steps repeatedly, until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck, put the next top card of the deck at the
bottom of the deck. If there are still unrevealed cards, go back to step 1.
Otherwise, stop. Return an ordering of the deck that would reveal the cards in
increasing order.

The first entry in the answer is considered to be the top of the deck.



Example 1:

Input: [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
Explanation:
We get the deck in the order [17,13,11,2,3,5,7] (this order doesn't matter), and
reorder it. After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is
the top of the deck. We reveal 2, and move 13 to the bottom.  The deck is now
[3,11,5,17,7,13]. We reveal 3, and move 11 to the bottom.  The deck is now
[5,17,7,13,11]. We reveal 5, and move 17 to the bottom.  The deck is now
[7,13,11,17]. We reveal 7, and move 13 to the bottom.  The deck is now
[11,17,13]. We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
We reveal 13, and move 17 to the bottom.  The deck is now [17].
We reveal 17.
Since all the cards revealed are in increasing order, the answer is correct.
*/

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    queue<int> deckq;
    for (int i = 0; i < deck.size(); ++i) {
        deckq.push(i);
    }
    vector<int> order;
    while (not deckq.empty()) {
        order.push_back(deckq.front());
        deckq.pop();

        if (deckq.empty()) {
            break;
        }
        deckq.push(deckq.front());
        deckq.pop();
    }
    vector<int> newdeck(deck.size(), 0);
    sort(deck.begin(), deck.end());
    for (int i = 0; i < order.size(); ++i) {
        newdeck[order[i]] = deck[i];
    }
    return newdeck;
}

vector<int> deckRevealedIncreasing2(vector<int>& deck) {
    deque<int> deckq;
    sort(deck.begin(), deck.end());
    deckq.push_back(deck.back());
    for (int i = 2; i <= deck.size(); ++i) {
        deckq.push_front(deckq.back());
        deckq.pop_back();
        deckq.push_front(deck[deck.size() - i]);
    }
    return {deckq.begin(), deckq.end()};
}

int main() {
    return 0;
}
