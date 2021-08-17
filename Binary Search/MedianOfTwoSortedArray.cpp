#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    if (n1 > n2)
        return findMedian(arr2, arr1);

    int l = 0, r = n1;

    while (l <= r)
    {
        int part1 = (l + r) / 2;
        int part2 = (n1 + n2 + 1) / 2 - part1;

        int l1, l2, r1, r2;
        if (part1 == 0)
            l1 = INT_MIN;
        else
            l1 = arr1[part1 - 1];
        if (part2 == 0)
            l2 = INT_MIN;
        else
            l2 = arr2[part2 - 1];

        if (part1 == n1)
            r1 = INT_MAX;
        else
            r1 = arr1[part1];
        if (part2 == n2)
            r2 = INT_MAX;
        else
            r2 = arr2[part2];

        // int l1 = part1==0 ? INT_MIN : arr1[part1-1];
        // int l2 = part2==0 ? INT_MIN : arr2[part2-1];

        // int r1 = part1==n1 ? INT_MAX : arr1[part1];
        // int r2 = part2==n2 ? INT_MAX : arr2[part2];

        if (l1 <= r2 and l2 <= r1)
        {
            if ((n1 + n2) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }
        else if (l1 > r2)
        {
            r = part1 - 1;
        }
        else
            l = part1 + 1;
    }

    return 0.0;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7, 10};
    vector<int> arr2 = {2, 3, 6, 15};
    cout << endl
         << endl;
    cout << findMedian(arr1, arr1) << endl;

    return 0;
}
