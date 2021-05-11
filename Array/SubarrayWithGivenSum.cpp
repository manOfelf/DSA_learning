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

void subarray(vec arr, int sum)
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
int main()
{
    subarray({2, 3, 4, 5, 6, 7}, 6);

    return 0;
}
