// 그래프 탐색 - 방문/원상복구 패턴 데모 (하드코딩)

const visited = [0, 0, 0, 0];
const adj = [[], [], [], []];
const v = [];

function print() {
  const out = v.map(i => String.fromCharCode(i + 'A'.charCodeAt(0))).join(' ');
  console.log(out);
}

function go(idx) {
  if (v.length === 3) {
    print();
    return;
  }

  for (const there of adj[idx]) {
    // 방문을 한 노드면 건너뛴다
    if (visited[there]) continue;
    // 방문을 한 노드를 체크
    visited[there] = 1;
    v.push(there);

    // 잘 들어갔는지 체크
    console.log("push_back :: there :: " + there);
    console.log(v.join(' '));

    // 해당 노드로 이동!
    go(there);
    // 방문을 한 노드를 원상복구
    visited[there] = 0;
    v.pop();

    // 잘 뺐는지 체크
    console.log("pop_back :: there :: " + there);
    console.log(v.join(' '));
  }
}

visited[0] = 1;

adj[0].push(1);
adj[1].push(2);
adj[1].push(3);
adj[1].push(0);
adj[2].push(1);
adj[3].push(1);

visited[0] = 1;
v.push(0);

go(0);
