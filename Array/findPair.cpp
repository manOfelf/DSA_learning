Given array of N positive no., also given a no. X.
Task is to find pair(i,j) such that:
* i<j
* A[i] = A[j]
* i*j is divisible by X.
Note: 1 based indexing is taken.

INPUT: A[]= {2,2,2}   X=2
OUTPUT: 2


// Given array of N positive no., also given a no. X.
// Task is to find pair(i,j) such that:
// * i<j
// * A[i] = A[j]
// * i*j is divisible by X.
// Note: 1 based indexing is taken.

// INPUT: A[]= {2,2,2}   X=2
// OUTPUT: 2

#include <bits/stdc++.h>
using namespace std;

int findPair(vector<int> A, int X)
{
    int pair = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] == A[j] and ((i + 1) * (j + 1)) % X == 0)
            {
                pair++;
            }
        }
    }

    return pair;
}

int main()
{
    cout << findPair({2, 2, 2}, 2) << endl;
}
