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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(typename T::iterator i1, typename T::iterator i2) {while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Design and implement a data structure for Least Recently Used (LRU) cache.

It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists
in the cache, otherwise return -1.

put(key, value) - Set or insert the value if the key is not already present.

When the cache reached its capacity, it should invalidate the least recently
used item before inserting a new item.
*/

class LRUCache {
	unordered_map<int, list<pair<int, int>>::iterator> buffer;
	list<pair<int, int>> active_order;
	const int cap;
public:
	LRUCache(int capacity) : cap(capacity)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	}

	int get(int key)
	{
		if (buffer.find(key) == buffer.end())
		{
			return -1;
		}

		list<pair<int, int>>::iterator tar = buffer[key];

		active_order.push_back(*tar);
		active_order.erase(tar);

		buffer[key] = prev(active_order.end(), 1);

		return buffer[key]->second;
	}

	void put(int key, int value)
	{
		if (buffer.find(key) == buffer.end() and buffer.size() == cap)
		{
			buffer.erase(active_order.front().first);

			active_order.pop_front();
			active_order.push_back(pair<int, int>(key, value));

			buffer[key] = prev(active_order.end(), 1);
		}
		else if (buffer.find(key) == buffer.end() and buffer.size() != cap)
		{
			active_order.push_back(pair<int, int>(key, value));
			buffer[key] = prev(active_order.end(), 1);
		}
		else if (buffer.find(key) != buffer.end())
		{
			list<pair<int, int>>::iterator tar = buffer[key];
			pair<int, int> item = *tar;
			item.second = value;

			active_order.erase(tar);
			active_order.push_back(item);
			buffer[key] = prev(active_order.end(), 1);
		}
	}
};

int main()
{
	LRUCache cache( 2 /* capacity */ );

	cache.put(2, 1);
	cache.put(2, 2);
	cout << cache.get(2) << '\n';       // returns 1
	cache.put(1, 1);
	cache.put(4, 1);
	cout << cache.get(2) << '\n';       // returns -1 (not found)

	return 0;
}
