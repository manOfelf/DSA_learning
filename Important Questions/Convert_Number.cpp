#include <bits/stdc++.h>

	using namespace std;

int explore(int n, int t)
{

	int x, y, z, d = abs(t - n), ans = 100000;

	if (n <= t)
	{
		for (int i = 0; i <= d / 3; i++)
		{
			for (int j = 0; j <= d / 2; j++)
			{
				for (int k = 0; k <= d; k++)
				{
					if (3 *i + 2 *j - k == d)
					{
						ans = min(i + j + k, ans);
					}
				}
			}
		}
	}
	else
		return 0;

	return ans;
}

int main()
{

	int num, target;
	cin >> num >> target;

	// Convert N to T by using:
	// +3
	// +2
	// -1

	cout << explore(num, target) << endl;

	return 0;
}
