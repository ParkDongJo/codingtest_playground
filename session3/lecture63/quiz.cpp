#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m;
// 문제의 범위보다 조금 더 위로
// 큰돌님의 방식
int arr[104][104];
int visited[104][104];

int result = 0;

/*
[문제]
종화는 21세기 유명한 방구쟁이다. 종화는 방구를 낄 때 "이러다... 다 죽어!!" 를 외치며 방구를
뀌는데 이렇게 방귀를 뀌었을 때 방귀는 상하좌우 네방향으로 뻗어나가며 종화와 연결된 "육지"는
모두 다 오염된다.
"바다"로는 방구가 갈 수 없다. 맵이 주어졌을 때 종화가 "이러다... 다 죽어!!"를
"최소한" 몇 번외쳐야 모든 육지를 오염시킬 수 있는지 말해보자. 1은 육지며 0은 바다를 가리킨다.


[입력]
맵의 세로길이 N과 가로길이 M 이 주어지고 이어서 N * M의 맵이 주어진다.

[출력]
"이러다... 다 죽어!!"를 몇 번 외쳐야하는지 출력하라.

[범위]
1 <= N <= 100
1 <= M <= 100


[예제입력]
5 5
1 0 1 0 1
1 1 0 0 1
0 0 0 1 1
0 0 0 1 1
0 1 0 0 0

[예제출력]
4
*/

// 언제 갯수를 세야햐지????

void dfs(int y, int x)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 | ny >= n | nx < 0 | nx >= m)
      continue;
    if (arr[ny][nx] == 0)
      continue;
    if (visited[ny][nx] == 1)
      continue;
    dfs(ny, nx);
  }
}

int main()
{

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

  return 0;
}
