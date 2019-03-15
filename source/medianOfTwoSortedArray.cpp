#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int len1 = nums1.size();
	int len2 = nums2.size();
	if(len1 == 0)
	{
		if(len2%2 == 0)
		{
			return (nums2[len2/2]+nums2[len2/2-1])/2.0;
		}
		else
		{
			return nums2[len2/2];
		}
	}
	if(len2 == 0)
	{
		if(len1%2 == 0)
		{
			cout << "h" << endl;
			return (nums1[len1/2]+nums1[len1/2-1])/2.0;
		}
		else
		{
			return nums1[len1/2];
		}
	}

	vector<int>::iterator ite1 = nums1.begin();
	vector<int>::iterator ite2 = nums2.begin();

	int tlen = len1 + len2;
	bool isOdd = (tlen % 2 == 1);
	int mid = tlen / 2 + 1;

	int cur = (*ite1 < *ite2) ? *ite1 : *ite2, prev = 0;
	while (mid--)
	{
		if (ite1 == nums1.end())
		{
			prev = cur;
			cur = *ite2;
			ite2++;
			continue;
		}

		if (ite2 == nums2.end())
		{
			prev = cur;
			cur = *ite1;
			ite1++;
			continue;
		}

		if (*ite1 < *ite2)
		{
			if (ite1 == nums1.begin())
			{
				prev = cur;
				cur = *ite1;
				ite1++;
			}
			else
			{
				prev = cur;
				if (ite1 == nums1.end())
				{
					cur = *ite2;
				}
				else
				{
					cur = *ite1;
				}
				ite1++;
			}
		}
		else
		{
			if (ite2 == nums2.begin())
			{
				prev = cur;
				cur = *ite2;
				ite2++;
			}
			else
			{
				prev = cur;
				if (ite2 == nums2.end())
				{
					cur = *ite1;
				}
				else
				{
					cur = *ite2;
				}
				ite2++;
			}
		}
	}
	if (isOdd)
	{
		return cur;
	}
	else
	{
		return (prev + cur) / 2.0;
	}
}

int main()
{
	vector<int> v1 {2, 3};
	vector<int> v2 {};

	cout << findMedianSortedArrays(v1, v2) << endl;

	return 0;
}