#include <bits/stdc++.h>

using namespace std;

// T.C. : O (1)
int Circular_Printer (string str)
{
  int time = 0;
  int current_idx = 1;
  for (int i = 0; i < str.length (); i++)
    {
      int next_idx = str[i] - 96;

      time +=min(abs (next_idx - current_idx),
	                min((26 - next_idx + current_idx), (26 - current_idx + next_idx)));
    
      current_idx = str[i] - 96;
    }

  return time;
}

int main()
{
  int T;
  cin >> T;
  while (T--){
      string str;
      cin >> str;
      cout << Circular_Printer(str) << " ";
    }


}
