const len = 4;

// 벡터로 자료구조를 쓸때
const adj = Array.from({ length: len }, () => []);
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

adj[0].push(1);
adj[0].push(2);

adj[1].push(0);
adj[1].push(2);

adj[2].push(0);
adj[2].push(1);

adj[3].push(0);

// node를 바로 출력하는 방법
for (let i = 0; i < len; i++) {
  let line = i + " : ";
  for (const to of adj[i]) {
    line += to + " ";
  }
  console.log(line);
}

// 2차원으로 출력하는 방법
for (let i = 0; i < len; i++) {
  let line = i + " : ";
  for (let j = 0; j < len; j++) {
    line += (adj[i][j] !== undefined ? adj[i][j] : "") + " ";
  }
  console.log(line);
}
