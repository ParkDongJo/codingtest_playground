# DFS

깊이 우선 탐색

각 깊이마다 가장 끝에 있는 리프노드까지 방문해가는 탐색 알고리즘

재귀적으로 호출하여 탐색하는 알고리즘

```c++

dfs(u, adj)
  // 방문한 노드 체크
  u.visited = true;

  // 인접리스트에 포함이 되어 있는 노드들이
  for (each v ⊂ adj[u])
     if (v.visited == false)
        dfs(v, adj)


```

## dfs 를 구현하는 방법

구현하는 방법은 총 2가지가 있음

1. 방문 할 노드의 방문 여부를 확인하는 방법

```c++
void dfs(int u) {
  visited[u] = 1;

  for (int v : adj[u]) {
     if (visited[v] == 0) {
        dfs(v);
     }
  }
}
```

2. 확인하지 않고, 일단 방문하고 보는 방법

```c++
void dfs(int u) {
  if (visited[u]) return;
  visited[u] = 1

  for (int v : adj[u]) {
     dfs(v);
  }
}
```
