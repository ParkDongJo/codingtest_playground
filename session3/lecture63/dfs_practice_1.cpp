#include <bits/stdc++.h>
using namespace std;

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int u)
{
  visited[u] = 1;

  for (int nu : adj[u])
  {
    if (visited[u] == 0)
    {
      dfs(nu);
    }
  }
  return;
}

int main()
{
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(4);
  adj[2].push_back(5);
  adj[4].push_back(2);
  return 0;
}