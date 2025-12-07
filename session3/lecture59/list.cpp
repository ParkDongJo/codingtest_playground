#include <bits/stdc++.h>
using namespace std;

const int len = 4;

// 벡터로 자료구조를 쓸때
vector<int> adj[len];
/*
 - n 번째 삽입, 삭제 : O(n)
 - 마지막 요소 삽입, 삭제 : O(1)
 - 특정요소 탐색 : O(n)
 - n 번째 요소 탐색 : O(1)
*/

// 연결리스트로 자료구조를 쓸때
// list<int> adj[len];
/*
 - n 번째 삽입, 삭제 : O(1)
 - 마지막 요소 삽입, 삭제 : O(1)
 - 특정요소 탐색 : O(n)
 - n 번째 요소 탐색 : O(n)
*/

int main()
{

  adj[0].push_back(1);
  adj[0].push_back(2);

  adj[1].push_back(0);
  adj[1].push_back(2);

  adj[2].push_back(0);
  adj[2].push_back(1);

  adj[3].push_back(0);

  // node를 바로 출력하는 방법
  for (int i = 0; i < len; i++)
  {
    cout << i << " : ";
    for (int to : adj[i])
    {
      cout << to << " ";
    }
    cout << endl;
  }

  // 2차원으로 출력하는 방법
  for (int i = 0; i < len; i++)
  {
    cout << i << " : ";
    for (int j = 0; j < len; j++)
    {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}