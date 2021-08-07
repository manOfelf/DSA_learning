#include <bits/stdc++.h>
using namespace std;
void mergeInterval(vector<pair<int, int>> arr)
{
    if (arr.size() <= 0)
        return;

    stack<pair<int, int>> s;
    s.push(arr[0]);

    for (auto i : arr)
    {
        pair<int, int> top = s.top();

        if (top.second < i.first)
            s.push(i);
        else if (top.second < i.second)
        {
            top.second = i.second;
            s.pop();
            s.push(top);
        }
    }
    while (!s.empty())
    {
        pair<int, int> top = s.top();
        cout << "[" << top.first << "," << top.second << "]"
             << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    mergeInterval({{1, 3}, {2, 6}, {5, 9}, {7, 12}});
}
