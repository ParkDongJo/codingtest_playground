#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;

int n, m;

int arr[max_n][max_n];
int visited[max_n][max_n];

/*
     0,1
-1,0  0  1,0
    0,-1
*/

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int result;

void dfs(int y, int x)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == 0)
      continue;
    if (visited[ny][nx] == 1)
      continue;
    dfs(ny, nx);
  }
}

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

  // dfs
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // 여기서 1을 체크한건 문제의 특성상!
      if (arr[i][j] == 1 && !visited[i][j])
      {
        dfs(i, j);
        result++;
      }
    }
  }

  cout << result;
}