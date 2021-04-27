#include<bits/stdc++.h>

using namespace std;

// T.C : O(log n)
bool isSqrtInteger(int n, int start, int end) {
  
  while (start <= end) {
    int mid = (start + end) / 2;
    if (mid * mid == n)
      return true;
    else if (mid * mid < n)
      start = mid + 1;
    else if (mid * mid > n)
      end = mid - 1;

  }
  return false;
}

int main() {
  int n;
  cin >> n;

  // isSqrtInteger( n, start, end)
  cout << isSqrtInteger(n, 1, n) << endl;

}
