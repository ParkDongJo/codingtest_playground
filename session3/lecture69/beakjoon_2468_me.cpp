#include <bits/stdc++.h>
using namespace std;

const int max_len = 104;
int m, n, ny, nx;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[max_len][max_len];
int ground[max_len][max_len];
int cnt = 0, cnt_max;

void dfs(int y, int x, int k)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx > m)
    {
      continue;
    }
    if (ground[ny][nx] < k && visited[ny][nx] != 0)
    {
      continue;
    }
    dfs(ny, nx, k);
    cnt++;
  }
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> ground[i][j];
    }
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (ground[i][j] > k && visited[i][j] != 0)
        {
          dfs(i, j, k);
          cnt_max = cnt;
          cnt = 0;
        }
      }
    }
  }

  cout << cnt_max;

  return 0;
}