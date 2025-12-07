#include <bits/stdc++.h>
using namespace std;

const int len = 5;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, x, y, ny, nx, my, mx;
int arr[len][len];
int visited[len][len];

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  queue<pair<int, int>> q;

  visited[0][0] = 1;

  q.push({0, 0});

  while (q.size())
  {
    // 타이란 어떤 역할을 해주느가
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m)
        continue;

      if (arr[ny][nx] == 0)
        continue;

      if (visited[ny][nx] == 1)
        continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  printf("%d", visited[n - 1][m - 1]);
  return 0;
}