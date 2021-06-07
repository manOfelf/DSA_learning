#include<bits/stdc++.h>
using namespace std;

int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1};

int ABCPath(char** grid, int n, int m, char startVertex, queue<pair<pair<int, int>, pair<int, char>>> A) {

	// created visited array for marking the location already visited
bool **vis = new bool *[n];
	for (int i = 0; i < n; i++)
	{
		vis[i] = new bool[m];
		for (int j = 0; j < m; j++)
			vis[i][j] = 0;
	}
	int max_path = -10000;
	while (!A.empty())
	{
		pair<pair<int, int>, pair<int, char>> v;
		v = A.front();
		int x = v.first.first, y = v.first.second;
		int d = v.second.first;
		char c = v.second.second;

		max_path = max(max_path, d);
		A.pop();
		vis[x][y] = 1;
		for (int i = 0; i < 8; i++)
		{
			int current_x = x + dx[i];
			int current_y = y + dy[i];

			if (current_x < n && current_y < m && current_x >= 0 && current_y >= 0 && grid[current_x][current_y] == c + 1)
			{
				if (!vis[current_x][current_y])
				{
					A.push({{current_x, current_y}, {d + 1, c + 1}});
				}
			}
		}
	}
	return max_path;
}
int main() {
	int n, m;
	cin >> n >> m; // n = 4, m = 3
  
//     n = 4, m = 3
//     A B E
//     C F G 
//     B D H
//     A B C

	queue<pair<pair<int, int>, pair<int, char>>> A;
	char** grid = new char*[n];
	for (int i = 0; i < n; i++) {
		grid[i] = new char[m];
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A')
				A.push({{i, j}, {1, 'A'}});
		}
	}


	cout << ABCPath(grid, n, m, 'A', A)<< endl;
  // 4
}
