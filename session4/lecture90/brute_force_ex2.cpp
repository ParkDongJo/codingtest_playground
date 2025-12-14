

/*
[문제]
홍철이는 3 * 3 맵에서 {0, 0} 지점에서 길을 잃어버렸다. 긍정왕 홍철이는 길을 잃어버린 김에 구걸을
하면서 돈을 모으면서 여행을 가려고 한다. 목적지는 {2, 2}이며 방문한 정점은 다시 방문할 수 없고
해당 맵에 구걸로 얻을 수 있는 돈들이 있다. 홍철이는 4방향(상하좌우)로 움직일 수 있다. {2,
2}까지 간다고 했을 때 이 돈들을 모으는 모든 경우의 수를 출력하여라.

[입력]
{10, 20, 21},
{70, 90, 12},
{80, 110, 120}




*/
#include <bits/stdc++.h>
using namespace std;

const int n = 3;
int a[3][3] = {
    {10, 20, 21},
    {70, 90, 12},
    {80, 110, 120}};
int visited[3][3];

// 상하좌우 방향
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<int> v;

void print()
{
  for (int i : v)
    cout << i << " ";
  cout << '\n';
}

void go(int y, int x)
{
  // 기저사례 : 목적지에 도달했을 때
  if (y == n - 1 && x == n - 1)
  {
    print();
    return;
  }

  // 상하좌우 방향으로 이동
  for (int i = 0; i < 4; i++)
  {
    // 다음 방향
    int ny = y + dy[i];
    int nx = x + dx[i];
    // 범위를 벗어날 때
    if (ny < 0 || nx < 0 || ny >= n || nx >= n)
      continue;

    // 이미 방문했을 때
    if (visited[ny][nx])
      continue;
    // 방문을 한 노드를 체크
    visited[ny][nx] = 1;
    v.push_back(a[ny][nx]);
    // 해당 노드로 이동
    go(ny, nx);

    // 방문을 한 노드를 원상복구
    visited[ny][nx] = 0;
    v.pop_back();
  }
}

int main()
{
  visited[0][0] = 1;
  v.push_back(a[0][0]);
  go(0, 0);
  return 0;
}