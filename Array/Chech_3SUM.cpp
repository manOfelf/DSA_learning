#include <bits/stdc++.h>

using namespace std;

//T.C : O(n*n) 
//S.C : O(1)

int TwoPointer(vector < int > arr, int l, int sum) {

  int r = arr.size() - 1;
  while (l < r) {

    if (sum == arr[l] + arr[r]) {
      return true;
    } else if (arr[l] + arr[r] > sum)
      r--;
    else
      l++;
  }
  return false;
}
bool Check_3SUM(vector < int > arr, int sum) {

  for (int i = 0; i < arr.size() - 1; i++) {

    int x = sum - arr[i];
    if (TwoPointer(arr, i + 1, x))
      return true;
  }
  return false;
}

int main() {
    int size, sum;
    cin >> size >> sum;
    vector < int > arr;
    for (int i = 0; i < size; i++) {

      int tem;
      cin >> tem;
      arr.push_back(tem);
    }

    cout << Check_3SUM(arr, sum) << endl;

    return 0;
