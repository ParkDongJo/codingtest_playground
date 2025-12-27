#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[50][50];
int visited[50][50];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int mx = 0;


void bfs(int y, int x)
{
  // 방문 배열 초기화
  memset(visited, 0, sizeof(visited));
  // 큐 초기화
  queue<pair<int, int>> q;
  // 시작점 큐에 넣기
  q.push({y, x});
  visited[y][x] = 1;

  while (q.size())
  {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m)
        continue;

      if (a[ny][nx] == 'W')
        continue;

      if (visited[ny][nx])
        continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});

      mx = max(mx, visited[ny][nx]);
    }

    q.pop();
  }
}

int main()
{

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 'L')
      {
        bfs(i, j);
      }
    }
  }

  cout << mx << '\n';
  return 0;
}