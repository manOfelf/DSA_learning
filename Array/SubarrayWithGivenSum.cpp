#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>

bool BinarySearch(vec arr, int val)
{
	int l = 1, r = arr.size() - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (val == arr[mid])
			return true;
		else if (arr[mid] < val)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}

vec prefix_sum(vec arr)
{
	vec prefixSum;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
		prefixSum.push_back(sum);
	}
	return prefixSum;
}

void subArray(vec arr, int sum)
{
	vec prefixSum = prefix_sum(arr);

	int r = prefixSum.size() - 1;
	for (int l = 1; r > l - 1; l++)
	{
		int rightsum = prefixSum[l - 1] + sum;
		if (BinarySearch(prefixSum, rightsum))
		{
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

void subArr(vec arr, int sum)
{
	int tem_sum = arr[0], l = 0;

	for (int i = 1; i < arr.size() - 1; i++)
	{
		while (tem_sum > sum && l < i - 1)
		{
			tem_sum = tem_sum - arr[i];
			l++;
		}

		if (tem_sum == sum)
		{
			cout << "The subarray found between " << l << " and " << i - 1 << endl;
			return;
		}
		if (i < arr.size())
			tem_sum += arr[i];
	}
	cout << "No subarray found\n";
	return;
}

int main()
{
	// SubArray by Sliding window technique
	//	subArr({2, 3, 4, 5, 6, 7}, 9);

	// SubArray by PrefixSum
	subArray({2, 3, 4, 5, 6, 7}, 9);

	return 0;
}
