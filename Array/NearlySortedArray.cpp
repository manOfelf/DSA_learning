#include <bits/stdc++.h>
using namespace std;

// T.C: O(NlogK)
void K_Sort(int arr[], int k, int size)
{
    int n;
    if (k == size)
        n = k;
    else
        n = k + 1;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);

    int j = 0; // for putting value in array from start
    for (int i = k + 1; i < size; i++)
    {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    // putting rest of the heap element in array
    while (!pq.empty())
    {
        arr[j++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10};
    K_Sort(arr, 3, 6);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
