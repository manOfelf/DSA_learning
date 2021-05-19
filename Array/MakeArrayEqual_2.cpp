#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>

// T.C : O(n)
int arraySum(vec arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    return sum;
}

int MakeArrayEqual(vec arr)
{

    int min = *min_element(arr.begin(), arr.end());

    int sum = arraySum(arr);

    int moves = sum - arr.size() * min;

    return moves;
}

int main()
{
    cout << MakeArrayEqual({3, 4, 6, 6, 3}) << endl;

    return 0;
}
