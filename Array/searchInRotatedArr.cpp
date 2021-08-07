#include <bits/stdc++.h>
using namespace std;

int searchInRotatedArr(const vector<int> &A, int B)
{
    int n = A.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (A[mid] == B)
            return mid;
        else if (A[0] <= A[mid])
        {
            if (A[0] <= B && B < A[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (A[mid] < B && B <= A[n - 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    cout << searchInRotatedArr({4, 5, 6, 0, 1, 2, 3}, 3) << endl;
}
