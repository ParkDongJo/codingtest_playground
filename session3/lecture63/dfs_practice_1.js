const n = 6;
const adj = Array.from({ length: n }, () => []);
const visited = new Array(n).fill(0);

function dfs(u) {
  visited[u] = 1;

  for (const nu of adj[u]) {
    if (visited[u] === 0) {
      dfs(nu);
    }
  }
  return;
}

adj[1].push(2);
adj[1].push(3);
adj[2].push(4);
adj[2].push(5);
adj[4].push(2);
