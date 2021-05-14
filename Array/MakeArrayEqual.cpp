#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>

// T.C : O(N)

void steps(vec arr)
{
    int count[5] = {0};
    for (int i = 0; i < arr.size(); i++)
        count[arr[i]]++;

    int temp = 0;
    int mid;
    for (int i = 1; i < 5; i++)
    {
        temp += count[i];
        if (temp > arr.size() / 2)
        {
            mid = i;
            break;
        }
    }
    int step = 0;
    for (int i = 1; i < 5; i++)
    {
        if (i != mid)
            step += count[i] * abs(i - mid);
    }
    cout << step << endl;
  // 1
  // 0
  // 6
}

int main()
{
    // 1 <= N <= 10^5
    // 1 <= Ai <= 4
    steps({1, 2, 1, 1, 1, 1, 1});
    steps({3, 3, 3});
    steps({1, 2, 2, 3, 4, 4});
    return 0;
}
