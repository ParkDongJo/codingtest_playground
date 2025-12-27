#include <bits/stdc++.h>
using namespace std;

const int len = 51;
int n, l, r, ny, nx;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int visited[len][len];
int ground[len][len];
int people_sum;
int cnt;
int temp;

void dfs_for_check(int y, int x)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    ny = y + dy[i];
    nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= n)
    {
      continue;
    }
    if (visited[ny][nx] != 0)
    {
      continue;
    }
    if (ground[ny][nx] < l && ground[ny][nx] > r)
    {
      continue;
    }
    visited[ny][nx] = 1;
    people_sum += ground[ny][nx];
    cnt++;
    dfs_for_check(ny, nx);
  }
}

void dfs_for_inject(int y, int x)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    ny = y + dy[i];
    nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= n)
    {
      continue;
    }
    if (visited[ny][nx] == 0)
    {
      continue;
    }

    ground[ny][nx] = temp;
    dfs_for_inject(ny, nx);
  }
}

int main()
{
  cin >> n >> l >> r;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> ground[i][j];
    }
  }

  bool flag = true;
  // 끝날때까지 계속 돈다면, while 로 제어!
  while (flag)
  {
    // 초기화
    people_sum = 0;
    cnt = 0;
    fill(&visited[0][0], &visited[0][0] + len * len, 0);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (visited[i][j] != 1)
        {
          dfs_for_check(i, j);
          temp = people_sum / cnt;
        }
      }
    }

    if (cnt == 0)
    {
      flag = false;
    }

    // 초기화
    fill(&visited[0][0], &visited[0][0] + len * len, 0);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (visited[i][j] == 1)
        {
          dfs_for_inject(i, j);
        }
      }
    }
  }
}