#include <bits/stdc++.h>
using namespace std;

/*
정점은 0번 부터 9번까지 10개의 노드가 있다. 1 - 2 / 1 - 3 / 3 - 4 라는 경로가 있다. (1번과 2번,
1번과 3번, 3번과 4번은 연결되어있다.) 이를 인접행렬로 표현하라.
*/

/*
0번부터 방문안한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문해서 출력하는
재귀함수를 만들어라. 여기서 정점을 방문하고 다시 방문하지 않게 만들어야 한다.
*/
const int len = 4;
int visited[len] = {0, 0, 0, 0};

bool arr[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 1},
    {0, 0, 1, 0}};

void visit(int from)
{
  visited[from] = 1;
  cout << from << " ";
  for (int i = 0; i < len; i++)
  {
    if (visited[i] == 1)
      continue;
    if (arr[from][i])
    {
      visit(i);
    }
  }
  return;
}

int main()
{
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len; j++)
    {
      if (arr[i][j] && visited[i] == 0)
      {
        cout << i << "부터" << j << "까지 경로가 있다";
        visit(i);
      }
    }
  }
  return 0;
}