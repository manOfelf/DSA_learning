#include <bits/stdc++.h>
using namespace std;
// T.C: O(N)

vector<int> moveZeroToEnd(vector<int> arr)
{
    int c = 0;
    // After this iteration all the non-zero ints accumulate toward left of the array (overlapping occurs)
    for (auto i : arr)
    {
        if (i != 0)
            arr[c++] = i;
    }
    // arr[] = [1,3,5,3,5] elements overlapped

    // put zero in the array till the size of the array
    while (c < arr.size())
        arr[c++] = 0;

    return arr;
}

int main()
{
    vector<int> v = moveZeroToEnd({0, 1, 0, 3, 5});
    for (auto i : v)
        cout << i << " ";
  // 1 3 5 0 0
}
