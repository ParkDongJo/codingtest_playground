const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const [n, m] = readLine().split(' ').map(Number);
const a = [];
for (let i = 0; i < n; i++) {
  a.push(readLine().split(''));
}

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
let mx = 0;

function bfs(sy, sx) {
  // 방문 배열 초기화
  const visited = Array.from({ length: n }, () => Array(m).fill(0));
  // 큐 초기화 (인덱스 기반)
  const q = [];
  let qi = 0;
  // 시작점 큐에 넣기
  q.push([sy, sx]);
  visited[sy][sx] = 1;

  while (qi < q.length) {
    const [y, x] = q[qi++];

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (a[ny][nx] === 'W') continue;
      if (visited[ny][nx]) continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push([ny, nx]);

      mx = Math.max(mx, visited[ny][nx]);
    }
  }
}

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (a[i][j] === 'L') {
      bfs(i, j);
    }
  }
}

// visited는 1부터 시작하므로 거리는 mx-1
console.log(mx - 1);
