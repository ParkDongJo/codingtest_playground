#include <bits/stdc++.h>
using namespace std;

const int n = 3;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int arr[n][n];
int visited[n][n];

/*
Q)

3 * 3 맵을 입력받아야 함. 이 맵은 1과 0으로 이루어져있고 {0, 0}은
무조건 1임을 보장한다. {0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며
방문한 정점은 다시 방문하지 않으며 방문하는 좌표
를 출력하는 코드. 0은 갈
수 없는 지역. 1은 갈 수 있는 지역을
구현하시오.

*/

void visit(int y, int x)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int nextY = y + dy[i];
    int nextX = x + dx[i];

    // 범위를 벗어날 때는 그냥 넘어가라
    if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
      continue;

    // 갈수 없는 지역에 대해서는 그냥 넘어가라
    if (arr[nextY][nextX] == 0)
      continue;

    // 곧 탐색할 정점이 이미 방문을 한 정점이라면 그냥 넘어가라
    if (visited[nextY][nextX])
      continue;

    visit(nextX, nextY);
  }
  return;
}

int main()
{

  // 행렬을 입력 받는다고 했을때
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  visit(0, 0);

  return 0;
}