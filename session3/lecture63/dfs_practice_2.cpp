#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[104][104];
int visited[104][104];

int result;

// 좌우방향
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{

  // dfs 는 bfs 와 달리 dfs 시작부터 방문체크를 한다.
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
  // 입력 셋팅
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; i++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // 육지이고, 방문하지 않았다면
      if (arr[j][i] == 1 && !visited[i][j])
      {
        dfs(i, j);
        result++;
      }
    }
  }
}