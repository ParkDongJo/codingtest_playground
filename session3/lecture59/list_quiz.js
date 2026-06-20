/*
Q1)
정점은 0번 부터 9번까지 10개의 노드가 있다. 1 - 2 / 1 - 3 / 3 - 4 라는 경로가 있다. (1번과 2번,
1번과 3번, 3번과 4번은 연결되어있다.)이를 인접리스트로 표현한자?

Q)
0번부터 방문안한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문해서 출력하는
재귀함수를 만들고 싶다면 어떻게 해야할까? 또한, 정점을 방문하고 다시 방문하지 않게 만드려면
어떻게 해야할까?

*/

const len = 10;
const adj = Array.from({ length: len }, () => []);
const visited = new Array(len).fill(0);

function visit(from) {
  visited[from] = 1;
  process.stdout.write(from + " ");
  for (const there of adj[from]) {
    if (visited[there]) continue;
    visit(there);
  }
  return
}

adj[1].push(2);
adj[1].push(3);

adj[2].push(1);

adj[3].push(1);
adj[3].push(4);

adj[4].push(3);

for (let i = 0; i < len; i++) {
  if (adj[i].length && visited[i] === 0)
    visit(i);
}
