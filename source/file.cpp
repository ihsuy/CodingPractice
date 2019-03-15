#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <utility>
using namespace std;

int lengthLongestPath(string input)
{
	vector<int> rootLenAtLv;
	int result = 0;

	int level = 0;
	int i = 0;

	bool isFile = false;
	int lenCount = 0;

	while (i < input.length() and input[i] != '\n')
	{
		if (input[i] == '.')
		{
			isFile = true;
		}

		if (input[i] != ' ')
		{
			lenCount++;
		}
		i++;
	}

	if (isFile)
	{
		return lenCount;
	}

	rootLenAtLv.push_back(lenCount + 1);

	for (; i < input.length();)
	{
		if (input[i] != '\t' and input[i - 1] == '\t')
		{	// at the beginning of file or dir name
			isFile = false;
			lenCount = 0;
			for (; input[i] != '\n' and i < input.length(); ++i)
			{
				if (input[i] == '.')
				{
					isFile = true;
				}
				if (input[i] != ' ')
				{
					lenCount++;
				}
			}

			int len = rootLenAtLv[level - 1] + lenCount;
			if (not isFile)
			{
				if (level > rootLenAtLv.size() - 1)
				{
					rootLenAtLv.push_back(len + 1);
				}
				else if (level == rootLenAtLv.size() - 1)
				{
					rootLenAtLv[rootLenAtLv.size() - 1] = len + 1;
				}
				else
				{
					rootLenAtLv[level] = len + 1;
				}
			}
			else if (len > result)
			{
				result = len;
			}

			level = 0;
		}
		else
		{
			if (input[i] == '\t')
			{
				level++;
			}
		}
		i++;
	}
	return result;
}

int main()
{
	//cout << depth("\\n\\t\\t");
	cout << lengthLongestPath("dir\n    file.txt") << endl;
	cout << lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
	return 0;
}