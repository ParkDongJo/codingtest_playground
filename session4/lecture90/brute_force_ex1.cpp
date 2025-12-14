#include <bits/stdc++.h>
using namespace std;
int visited[4];
vector<int> adj[4];
vector<int> v;

void print()
{
  for (int i : v)
    cout << char(i + 'A') << " ";
  cout << '\n';
}

void go(int idx)
{
  if (v.size() == 3)
  {
    print();
    return;
  }

  for (int there : adj[idx])
  {
    // 방문을 한 노드면 건너뛴다
    if (visited[there])
      continue;
    // 방문을 한 노드를 체크
    visited[there] = 1;
    v.push_back(there);

    // 잘 들어갔는지 체크
    cout << "push_back :: there :: " << there << "\n";
    for (int i : v)
      cout << i << " ";
    cout << "\n";

    // 해당 노드로 이동!
    go(there);
    // 방문을 한 노드를 원상복구
    visited[there] = 0;
    v.pop_back();

    // 잘 뺐는지 체크
    cout << "pop_back :: there :: " << there << "\n";
    for (int i : v)
      cout << i << " ";
    cout << "\n";
  }
}

int main()
{
  visited[0] = 1;

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[1].push_back(0);
  adj[2].push_back(1);
  adj[3].push_back(1);

  visited[0] = 1;
  v.push_back(0);

  go(0);
  return 0;
}