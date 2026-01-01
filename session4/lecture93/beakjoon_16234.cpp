#include <bits/stdc++.h>
using namespace std;
int visited[54][54], a[54][54], n, l, r, sum, cnt;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

// 연산을 해야하는 좌표 집합
vector<pair<int, int>> v;

void dfs(int y, int x)
{
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx])
      continue;
    
      // abs 로 절대값에 대한 계산
      // 소수점 제거라고 했을 시 사용
    if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r)
    {
      visited[ny][nx] = 1;
      // 좌표 넣고
      v.push_back({ny, nx});
      // 인구합
      sum += a[ny][nx];
      dfs(ny, nx);
    }
  }
}

int main()
{
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  while (true)
  {
    // flag 를 false 부터 시작
    bool flag = 0;
    // 초기화
    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // 방문할 것이 더이상 없다면,
        // 최상위 루프를 벗어나아함
        if (!visited[i][j])
        {
          // 좌표 초기화
          v.clear();
          visited[i][j] = 1;
          // 좌표 넣기
          v.push_back({i, j});
          // 인구 합
          sum = a[i][j];

          dfs(i, j);
          if (v.size() == 1)
            continue;

          // 인구 주입
          for (pair<int, int> b : v)
          {
            a[b.first][b.second] = sum / v.size();
            // 주입을 하고 나서는 한번 더 돌게끔 flag true
            flag = 1;
          }
        }
      }
    }
    if (!flag)
      break;
    cnt++;
  }
  cout << cnt << "\n";
  return 0;
}