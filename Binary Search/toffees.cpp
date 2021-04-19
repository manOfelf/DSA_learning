#include <bits/stdc++.h>
#define v_int vector < int>

using namespace std;

// T.C : N * log(N)
bool is_valid(v_int arr, int m, int mx)
{
	int box = 1;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum = sum + arr[i];
		if (sum > mx)
		{
			box++;
			sum = arr[i];
		}
		if (box > m)
			return false;
	}
	return true;

}

int toffees(v_int arr, int m)
{
	int start = *max_element(arr.begin(), arr.end()), end = 0;
	for (int i = 0; i < arr.size(); i++)
		end += arr[i];

	int res = -1;

	if (arr.size() < m)
		return res;

	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (is_valid(arr, m, mid))
		{
			res = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return res;

}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        v_int arr;

        for (int i = 0; i < n; i++)
        {
            int tem;
            cin >> tem;
            arr.push_back(tem);
        }
        cout << toffees(arr, m) << endl;
    }
	

}
