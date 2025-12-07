#include <bits/stdc++.h>
using namespace std;

/*
[문제]
승원이는 당근을 좋아해서 당근마킷에 엔지니어로 취업했다. 당근을 매우좋아하기 때문에 차도
당근차를 샀다. 이 당근차는 한칸 움직일 때마다 당근을 내뿜으면서 간다. 즉,
"한칸" 움직일 때
"당근한개"가 소모된다는 것이다. 승원이는 오늘도 아침 9시에 일어나 당근마킷으로 출근하고자
한다. 승원이는 최단거리로 당근마킷으로 향한다고 할 때 당근몇개를 소모해야 당근마킷에 갈 수
있는지 알아보자. 이 때 승원이는 육지로만 갈 수 있으며 바다로는 못간다. 맵의 1은 육지며 0은
바다를 가리킨다. 승원이는 상하좌우로만 갈 수 있다.

[입력]
맵의 세로길이 N과 가로길이 M 이 주어지고 이어서 N * M의 맵이 주어진다. 그 다음 줄에 승원이의
위치(y, x)와 당근마킷의 위치(y, x)가 주어진다. 이 때 승원이의 시작위치(y, x)에서 "당근한개"가
이미 소모된 상태로 본다.

[출력]
당근을 몇개 소모해야 하는지 출력하라.

[범위]
1 <= N <= 100
1 <= M <= 100

[예제입력]
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
[예제출력]
9

*/

const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x, sy, sx, ey, ex;

int main()
{
  // scanf vs. cin 둘중에 뭐든 상관없지만, 쓸거면 하나만 쓰자!!
  // scanf("%d %d", &n, &m);
  cin >> n >> m;
  cin >> sy >> sx;
  cin >> ey >> ex;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  // 2차원 좌표이기 때문에!
  queue<pair<int, int>> q;

  // 첫 시작지점은 체크를 해준다
  visited[sy][sx] = 1;
  // 첫 시작지점을 큐에 넣어준다
  q.push({sy, sx});

  while (q.size())
  {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      // 더이상 갈수 없는 바다라면
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0)
        continue;

      // 이미 방문을 한 지점이라면
      if (visited[ny][nx])
        continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
  printf("%d\n", visited[ey][ex]);

  // 최단거리 디버깅
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << visited[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}