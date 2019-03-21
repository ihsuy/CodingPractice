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
#include <string>

typedef long long ll;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
template<typename T>
inline void inspect(T& t){typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving 
the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

struct capsule
{
	int val;
	int cur_min;

	capsule(const int& v, const int& cm):val(v), cur_min(cm){}
};

class MinStack2 {
	stack<capsule> storage;
public:
    MinStack2()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    void push(int x) 
    {	
    	int min_val;
    	if(storage.empty())
    	{
    		min_val = x;
    	}
        else if(x < storage.top().cur_min)
        {
        	min_val = x;
        }
        else
        {
        	min_val = storage.top().cur_min;
        }
        storage.push(capsule(x, min_val));
    }
    
    void pop() 
    {
        if(storage.size() != 0)
        {
        	storage.pop();
        }
        else
        {
        	throw runtime_error("Can't pop an empty minStack.");
        }
    }
    
    int top() 
    {
        if(storage.size() != 0)
        {
        	return storage.top().val;
        }
        else
        {
        	throw runtime_error("Can't get top from an empty minStack.");
        }
    }
    
    int getMin() 
    {
        return storage.top().cur_min;
    }
};

class MinStack {
	stack<int> storage;
	int min_val;
public:
    MinStack() : min_val(INT_MAX)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    
    void push(int x) 
    {
        if(x < min_val)
        {
        	min_val = x;
        }
        storage.push(x);
    }
    
    void pop() 
    {
        if(storage.size() != 0)
        {
        	if(storage.top() == min_val)
        	{
        		storage.pop();
        		stack<int> buffer;

        		min_val = INT_MAX;
        		while(not storage.empty())
        		{
        			int temp = storage.top();

        			if(temp < min_val)
        			{
        				min_val = temp;
        			}

        			buffer.push(temp);
        			storage.pop();
        		}
        		while(not buffer.empty())
        		{
        			storage.push(buffer.top());
        			buffer.pop();
        		}
        	}
        	else
        	{
        		storage.pop();
        	}
        }
        else
        {
        	throw runtime_error("Can't pop an empty minStack.");
        }
    }
    
    int top() 
    {
        if(storage.size() != 0)
        {
        	return storage.top();
        }
        else
        {
        	throw runtime_error("Can't get top from an empty minStack.");
        }
    }
    
    int getMin() 
    {
        return min_val;
    }
};


int main()
{
	MinStack2 minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;    
	minStack.pop();
	cout << minStack.top() << endl;
	cout << minStack.getMin() << endl; 

	return 0;
}
