#include <bits/stdc++.h>
using namespace std;
int a[101][101], e[101][101], visited[101][101], n, temp, ret = 1;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
void dfs(int y, int x, int d)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n)
      continue;
    if (!visited[ny][nx] && a[ny][nx] > d)
      dfs(ny, nx, d);
  }
  return;
}
int main()
{
  // 왜 이런 작업들이 들어가는지 한번 더 집고 넘어가자
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  // d(비가 오는 범위)가 100까지 될 수 있다고 했으니, 101 전까지 최상위에서 루프를 돌렸어야함
  for (int d = 1; d < 101; d++)
  {
    // 테스트 케이스 100번을 돌때마다 visited 를 초기화 시킨다.
    fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (a[i][j] > d && !visited[i][j])
        {
          dfs(i, j, d);
          cnt++;
        }
      }
    }
    ret = max(ret, cnt);
  }
  cout << ret << '\n';
  return 0;
}