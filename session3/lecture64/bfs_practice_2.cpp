#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n, m, startY, startX, endY, endX;

// 좌우 방향
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int arr[max_n][max_n], visited[max_n][max_n];

queue<pair<int, int>> q;
int qy, qx;

int main()
{
  cin >> n >> m;
  cin >> startY >> startX;
  cin >> endY >> endX;

  // 입력값 셋팅 완료
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  // 최초 방문체크
  visited[startY][startX] = 1;

  q.push({startY, startX});

  while (q.size())
  {
    tie(qy, qx) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {

      int nextY = qy + dy[i];
      int nextX = qx + dx[i];

      if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || arr[nextY][nextX] == 0)
      {
        continue;
      }
      if (visited[nextY][nextX])
      {
        continue;
      }

      // dfs 는 bfs 와 달리 dfs 모든 사전조건을 피했을 때, 방문체크를 한다

      visited[nextY][nextX] = visited[qy][qx] + 1;
      q.push({nextY, nextX});
    }
  }

  return 0;
}