#include <bits/stdc++.h>
using namespace std;

// T.C: O(N logN)

string NextGreaterNumber(string num)
{
    long long int i, n = num.size();
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (num[i] > num[i - 1])
            break; // when encounter smaller no.
    }

    if (i == 0)
        return "-1";

    int x = i;
    for (long long int j = i + 1; j < n; j++)
    { // finding the element we want to swap
        if (num[i - 1] < num[j] && num[j] < num[x])
            x = j;
    }

    char tem = num[x];
    num[x] = num[i - 1];
    num[i - 1] = tem;

    sort(num.begin() + i, num.end());

    return num;
}

int main()
{
    string num = "218765";
    cout << NextGreaterNumber(num) << endl;
    //  251678
}
