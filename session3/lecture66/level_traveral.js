// 인접리스트 그래프 표현
const adj = Array.from({ length: 1004 }, () => []);
// 방문 여부 체크
let visited = new Array(1004).fill(0);

function postOrder(here) {
  if (visited[here] === 0) {
    if (adj[here].length === 1)
      // here 의 자식 노드 중 첫번째 노드를 탐색
      postOrder(adj[here][0]);
    if (adj[here].length === 2) {
      // here 의 자식 노드 중 첫번째 노드와 두번째 노드를 탐색
      postOrder(adj[here][0]);
      postOrder(adj[here][1]);
    }
    visited[here] = 1;
    process.stdout.write(here + ' ');
  }
}

function preOrder(here) {
  if (visited[here] === 0) {
    visited[here] = 1;
    process.stdout.write(here + ' ');
    if (adj[here].length === 1)
      preOrder(adj[here][0]);
    if (adj[here].length === 2) {
      preOrder(adj[here][0]);
      preOrder(adj[here][1]);
    }
  }
}

function inOrder(here) {
  if (visited[here] === 0) {
    if (adj[here].length === 1) {
      inOrder(adj[here][0]);
      visited[here] = 1;
      process.stdout.write(here + ' ');
    } else if (adj[here].length === 2) {
      inOrder(adj[here][0]);
      visited[here] = 1;
      process.stdout.write(here + ' ');
      inOrder(adj[here][1]);
    } else {
      visited[here] = 1;
      process.stdout.write(here + ' ');
    }
  }
}

adj[1].push(2);
adj[1].push(3);
adj[2].push(4);
adj[2].push(5);
const root = 1;

console.log("\n 트리순회 : postOrder ");
postOrder(root);
visited = new Array(1004).fill(0);

console.log("\n 트리순회 : preOrder ");
preOrder(root);
visited = new Array(1004).fill(0);

console.log("\n 트리순회 : inOrder ");
inOrder(root);
