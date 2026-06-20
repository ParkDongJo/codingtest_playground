const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const len = 5;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let n, m, y, x;
const arr = Array.from({ length: len }, () => Array(len).fill(0));
const visited = Array.from({ length: len }, () => Array(len).fill(0));

const [N, M] = readLine().split(' ').map(Number);
n = N; m = M;

for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < m; j++) {
    arr[i][j] = row[j];
  }
}

const q = [[0, 0]];
let qi = 0;

visited[0][0] = 1;

while (qi < q.length) {
  // 타이란 어떤 역할을 해주느가
  const [y, x] = q[qi++];

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
      continue;

    if (arr[ny][nx] === 0)
      continue;

    if (visited[ny][nx] === 1)
      continue;

    visited[ny][nx] = visited[y][x] + 1;
    q.push([ny, nx]);
  }
}

console.log(visited[n - 1][m - 1]);
