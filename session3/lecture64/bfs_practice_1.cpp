#include <bits/stdc++.h>
using namespace std;

// n 개보다 좀 더 많게
const int max_n = 104;
// 좌우 방향
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 입력값
int n, m, sy, sx, ey, ex;
// 셋팅해야하는 상태
int a[max_n][max_n], visited[max_n][max_n];

// 큐 셋팅
queue<pair<int, int>> q;

// q에 뺀 값
int qy, qx;

int main()
{
  // 입력값 받기
  cin >> n >> m;
  cin >> sy >> sx;
  cin >> ey >> ex;

  // 자료구조 셋팅
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
  /*
    여기서 체크할 점!!! BFS 는 우선 재귀적인 접근보다는 반복문을 통한 접근부터 하ㅅ자!!
    특히 주로 이렇게 배열구조에서 최단거리, 최소, 최대 등등의 문제들이 나올것이다.
    이때 재귀적으로 접근하기보다, 지금 배운 방법 그대로 배열의 반복문 접근으로 시작하자
  */

  // 첫 시작지점은 체크를 해준다
  visited[sy][sx] = 1;
  // 첫 시작지점을 큐에 넣어준다
  q.push({sy, sx});

  while (q.size())
  {
    // 여기서 tie 는 어떤 역할인가?
    tie(qy, qx) = q.front();
    q.pop();

    // 좌우 방향을 돌아본다
    for (int i = 0; i < 4; i++)
    {
      int ny = qy + dy[i];
      int nx = qx + dx[i];

      // 더이상 갈수 없는 바다라면
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0)
        continue;

      // 이미 방문을 한 지점이라면
      if (visited[ny][nx])
        continue;

      // 여기서! 최단거리를 묻는 문제이다.
      // BFS 의 전제는 각각의 간선 가중치가 동일하고 1이라는 전제하에 진행된다.
      // 그래서 각 다음 정점을 방문할 때마다, 지금 정점의 가중치에 +1 을 해준다.
      visited[ny][nx] = visited[qy][qx] + 1;
      q.push({ny, nx});
    }
  }
}