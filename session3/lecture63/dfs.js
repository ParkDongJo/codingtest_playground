const n = 6;
const adj = Array.from({ length: n }, () => []);
const visited = new Array(n).fill(0);

// u 는 방문한 정점
function DFS(u) {
  visited[u] = 1;
  console.log(u);

  for (const v of adj[u]) {
    if (visited[v] === 0) {
      DFS(v);
    }
  }
  console.log(u + "로부터 시작된 함수가 종료되었습니다.");
  return;
}

adj[1].push(2);
adj[1].push(3);
adj[2].push(4);
adj[2].push(5);
adj[4].push(2);
DFS(1);

/*
1
2
4
5
3
*/
// 4로부터 시작된 함수가 종료되었습니다.
// 5로부터 시작된 함수가 종료되었습니다.
// 2로부터 시작된 함수가 종료되었습니다.
// 3로부터 시작된 함수가 종료되었습니다.
// 1로부터 시작된 함수가 종료되었습니다.
