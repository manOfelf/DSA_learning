#include <bits/stdc++.h>
using namespace std;
// T.C : O(n)
vector<string> ReverseByWord(string s)
{
    vector<string> ans;
    string word = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans.push_back(word);
            word = "";
        }
        else
        {
            word += s[i];
        }
    }
    ans.push_back(word);

    return ans;
}

int main()
{
    vector<string> s = ReverseByWord("Top of the world");
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i] << " ";
    }
  // world the of Top
}
