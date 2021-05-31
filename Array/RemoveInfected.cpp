#include <bits/stdc++.h>
using namespace std;
#define vec vector<vector<int>>
#define ll long long

// T.C : O(n*m) 

vec arr;
int n, m;
int removeInfected = 0;
void CountInfected(vec &arr, int i, int j)
{
    if (j == m - 1 && i < n - 1)
    {
        if (arr[i + 1][j] == 1)
            arr[i][j] = 0, removeInfected++;
    }
    else if (i == n - 1 && j < m - 1)
    {
        if (arr[i][j + 1] == 1)
            arr[i][j] = 0, removeInfected++;
    }
    else if (i < n - 1 && j < m - 1)
    {
        if (arr[i + 1][j] == 1 || arr[i][j + 1] == 1)
        {
            arr[i][j] = 0;
            removeInfected++;
        }
    }
}

void CountHealthy(vec &arr, int i, int j)
{
    if (j == m - 1 && i < n - 1)
    {
        if (arr[i + 1][j] == -1)
            arr[i + 1][j] = 0, removeInfected++;
    }
    else if (i == n - 1 && j < m - 1)
    {
        if (arr[i][j + 1] == -1)
            arr[i][j + 1] = 0, removeInfected++;
    }
    else if (i < n - 1 && j < m - 1)
    {
        if (arr[i + 1][j] == -1)
        {
            arr[i + 1][j] = 0;
            removeInfected++;
        }
        if (arr[i][j + 1] == -1)
        {
            arr[i][j + 1] = 0;
            removeInfected++;
        }
    }
}

void RemoveInfected(vec &arr)
{
    n = arr.size();
    m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
                CountHealthy(arr, i, j);
            else if (arr[i][j] == -1)
                CountInfected(arr, i, j);

            // cout << arr[i][j] << " "; //for grid printing after removal of infected people
        }
        // cout << endl;
    }

    cout << removeInfected << endl;
}

int main()
{
    arr = {{1, -1, 1, 1}, {-1, 1, 1, -1}, {0, 0, 0, -1}, {-1, 1, 1, -1}};
    RemoveInfected(arr);

    return 0;
}
