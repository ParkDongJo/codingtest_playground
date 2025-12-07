# BFS

같은 가중치를 가진 그래프에서 최단거리알고리즘으로 쓰입니다
Queue 라는 자료구조를 활용한다

- 방문한 노드 큐에 push
- 인접해있는 자식 노드 push + 동시에 방문했던 노드 pop
- 인접해있는 자식 노드 없으면 바로 pop

```c++

bfs(u, adj)
  // 방문한 노드 체크
  u.visited = true;
  q.push(u);

  // 인접리스트에 포함이 되어 있는 노드들이
  while(q.size())
    u = q.front()
    q.pop()

    for (each v ⊂ adj[u])
      if (v.visited == false)
        v.visited = true
        q.push(v)

```

## 가중치를 줬을 때

```c++

bfs(u, adj)
  queue<int> q;
  // 시작점 노드 체크
  u.visited = 1;
  q.push(u);

  // 인접리스트에 포함이 되어 있는 노드들이
  while(q.size())
    u = q.front()
    q.pop()

    for (each v ⊂ adj[u])
      if (v.visited == false)
        // 이 차이를 집중해야한다
        // bfs 는 레벨(계층) 별로 각 간선의 가중치를 기록하면, 각 정점마다의 최종 가중치가 정해진다.
        v.visited = u.visited + 1
        q.push(v)

```

## 가중치가 각 간선이 2일때

visited[n] \* 2

를 하면 된다.

## 시작지점이 여러개(예시 3개) 일때

```c++

bfs(adj)
  queue<int> q;

  for (int i = 1; i <= 3; i++) {
    u.visited = 1;
    q.push(i);

  // 인접리스트에 포함이 되어 있는 노드들이
  while(q.size())
    u = q.front()
    q.pop()

    for (each v ⊂ adj[u])
      if (v.visited == false)
        // 이 차이를 집중해야한다
        // bfs 는 레벨(계층) 별로 각 간선의 가중치를 기록하면, 각 정점마다의 최종 가중치가 정해진다.
        v.visited = u.visited + 1
        q.push(v)

```


## 가중치가 다른 그래프에서는?
BFS 로만 가지고는 안된다!!

이때는 최단거리 알고리즘
- 다익스트라
- 벨만포드

등등을 사용해야함