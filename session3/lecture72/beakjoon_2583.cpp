#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

int a[104][104], m, n, k, x1, x2, y1, y2, visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<int> ret;

int dfs(int y, int x)
{
  visited[y][x] = 1;
  int ret = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] == 1)
      continue;
    if (a[ny][nx] == 1)
      continue;

    // 탐색을 하게 되면 칸 갯수를 +1 씩 한다.
    ret += dfs(ny, nx);
  }
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m >> n >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> x1 >> y1 >> x2 >> y2;

    // 입력을 받자마자 바로 만든다..
    // 나는 포지션에 넣었다가, 그걸 또 다시 꺼내는 방향으로 생각했는데
    // 그러다보니 담는 자료구조, 꺼내서 다시 담는 자료구조 등등의 구조 복잡도가 증가해서 생각이 꼬였는데...
    // 그냥 입력 받자마자 바로 그 해당 구조에 넣는 방법으로 하니 훨씬 생각이 편하다
    for (int x = x1; x < x2; x++)
    {
      for (int y = y1; y < y2; y++)
      {
        a[y][x] = 1;
      }
    }
  }

  // 그리고 그 구조를 탐색하면서 갯수를 체크한다.
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (a[i][j] != 1 && visited[i][j] == 0)
      {
        ret.push_back(dfs(i, j));
      }
    }
  }

  // 그 크기를 정렬한다.
  sort(ret.begin(), ret.end());
  cout << ret.size() << "\n";
  for (int a : ret)
    cout << a << " ";
  return 0;
}