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
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }
template<typename T>
inline void inspect(T& t) {typename T::iterator i1 = t.begin(), i2 = t.end(); while (i1 != i2) {std::cout << (*i1) << ' '; i1++;} std::cout << '\n';}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Equations are given in the format A / B = k, where A and B are variables
represented as strings, and k is a real number (floating point number).
Given some queries, return the answers. If the answer does not exist,
return -1.0.
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].
*/

struct divisionNode
{
	vector<divisionNode*> neighbours;
	unordered_map<divisionNode*, double> values;

	void add_neighbour(divisionNode* node, const double& val)
	{	// create mutual edge
		values[node] = val;
		neighbours.push_back(node);
		node->values[this] = 1.0 / val;
		node->neighbours.push_back(this);
	}
};

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
{	// note that this is a graph problem

	// create the graph
	unordered_map<string, divisionNode*> vars;

	for (int i = 0; i < equations.size(); ++i)
	{
		if (vars.count(equations[i].first) == 0)
		{
			divisionNode* n = new divisionNode();
			if (vars.count(equations[i].second) != 0)
			{
				n->add_neighbour(vars[equations[i].second], values[i]);
			}
			else
			{
				divisionNode* n2 = new divisionNode();
				n->add_neighbour(n2, values[i]);
				vars[equations[i].second] = n2;

			}
			vars[equations[i].first] = n;

		}
		else
		{
			if (vars.count(equations[i].second) != 0)
			{
				vars[equations[i].first]->add_neighbour(vars[equations[i].second], values[i]);
			}
			else
			{
				divisionNode* n2 = new divisionNode();
				vars[equations[i].first]->add_neighbour(n2, values[i]);
				vars[equations[i].second] = n2;

			}
		}
	}

	// do the bfs
	vector<double> result;
	for (int i = 0; i < queries.size(); ++i)
	{
		string from_var = queries[i].first;
		string to_var = queries[i].second;

		if (vars.count(from_var) == 0 or vars.count(to_var) == 0)
		{
			result.push_back(-1.0);
			continue;
		}

		if (from_var == to_var)
		{
			result.push_back(1.0);
			continue;
		}

		queue<pair<divisionNode*, double>> todo;
		todo.push({vars[from_var], 1.0});

		unordered_set<divisionNode*> visited;

		bool found = false;
		while (not todo.empty())
		{
			auto p = todo.front();
			auto current_node = p.first;
			auto current_val = p.second;
			todo.pop();

			if (current_node == vars[to_var])
			{
				result.push_back(current_val);
				found = true;
			}

			for (int j = 0; j < current_node->neighbours.size(); ++j)
			{
				if (visited.count(current_node->neighbours[j]) == 0)
				{
					todo.push({current_node->neighbours[j], current_val * current_node->values[current_node->neighbours[j]]});
					visited.insert(current_node->neighbours[j]);
				}
			}
		}
		if (not found)
		{
			result.push_back(-1.0);
		}
	}

	return result;
}


int main()
{
	vector<pair<string, string>> vp {{"a", "b"}, {"e", "f"}, {"b", "e"}};
	vector<double> values {3.4, 1.4, 2.3};
	vector<pair<string, string>> queries{{"b", "a"}, {"a", "f"}, {"f", "f"}, {"e", "e"}, {"c", "c"}, {"a", "c"}, {"f", "e"}};

	auto result = calcEquation(vp, values, queries);

	inspect<vector<double>>(result);

	return 0;
}

