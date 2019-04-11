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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderSuccessor_helper(TreeNode* root, TreeNode* p, bool& found, TreeNode* result)
{
	if (root != nullptr)
	{
		inorderSuccessor_helper(root->left, p, found, result);
		//int mid = root->val;

		if (root == p)
		{
			found = true;
		}

		inorderSuccessor_helper(root->right, p, found, result);

		if (found)
		{
			result = root;
			found = false;
		}
	}
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{	// is there duplicates?
	TreeNode* result = nullptr;
	bool found = false;
	inorderSuccessor_helper(root, p, found, result);
	return result;
}

TreeNode* inorderSuccessor_iterative(TreeNode* root, TreeNode* p)
{	// is there duplicates?
	if (root == nullptr or p == nullptr)
	{
		return nullptr;
	}

	TreeNode* tmp = p->right;
	if (tmp)
	{
		while (tmp->left != nullptr)
		{
			tmp = tmp->left;
		}

		return tmp;
	}

	TreeNode* result = nullptr;

	while (root != nullptr)
	{
		if (root->val > p->val)
		{
			result = root;
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}

	return result;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
{
	if (root == nullptr or p == nullptr)
	{
		return nullptr;
	}

	TreeNode* prev_high = nullptr;
	while (root != nullptr)
	{
		if (root->val > p->val)
		{
			prev_high = root;
			root = root->left;
		}
		else if (root == p)
		{
			if (root->right != nullptr)
			{
				root = root->right;
				while (root->left != nullptr)
				{
					root = root->left;
				}
				return root;
			}
			else
			{
				return prev_high;
			}
		}
		else
		{
			root = root->right;
		}
	}
	return prev_high;
}

int main()
{


	return 0;
}
