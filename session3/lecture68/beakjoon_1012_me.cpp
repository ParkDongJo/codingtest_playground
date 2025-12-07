#include <bits/stdc++.h>
using namespace std;

int tc, result;
const int len = 54;

int arr[len][len];
int visited[len][len];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, k, y, x;

// 큰돌님은 arr, visited 를 모두 고정으로 최대로 잡아줬다.
// 나같은 경우는 m, n을 받고 곧바로 arr, visited 를 설정해주다 보니 같이 넘겨야했는데
// 알고리즘을 풀때는.. 그냥!! 제약사항이 없다면 미리 잡아두는것이 로직을 더 간단하게 만드는것 같다
void dfs(int y, int x)
{
  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
    {
      continue;
    }
    if (arr[y][x] == 0)
    {
      continue;
    }
    if (visited[y][x] == 1)
    {
      continue;
    }
    dfs(ny, nx);
  }
  return;
}

int main()
{
  // 이게 뭐하는 역할일까?
  // 성능 최적화를 위해
  // cin.tie(NULL)로 이 연결을 끊어서 불필요한 flush를 방지합니다
  cin.tie(NULL);
  cout.tie(NULL);
  /*
    놓친 부분이 있다!! tc 만큼 이 로직이 반복해서 돌건데, 그럴려면 1개의 tc가 끝나면 그 다음 tc 를 위해서
    데이터 셋에 대한 초기화가 필요하다.
    초기화를 해주는 코드를 넣어줘야한다
  */
  cin >> tc;
  cin >> n >> m >> k;

  int arr[n][m];
  int visited[n][m];

  for (int i = 0; i < k; i++)
  {
    cin >> x >> y;
    arr[y][x] = 1;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (arr[i][j] == 1 && visited[i][j] == 0)
      {
        result++;
        cout << 'test';
        dfs(i, j);
      }
    }
  }

  cout << result << "-정답\n";
  return 0;
}