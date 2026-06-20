const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
let m, n, k, y, x, ret, ny, nx, t;
let a = Array.from({ length: 51 }, () => Array(51).fill(0));
let visited = Array.from({ length: 51 }, () => Array(51).fill(false));

function dfs(y, x) {
  visited[y][x] = true;
  for (let i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
      continue;
    if (a[ny][nx] === 1 && !visited[ny][nx]) {
      dfs(ny, nx);
    }
  }
  return;
}

t = Number(readLine());
while (t--) {
  // 매 tc 마다 초기화 시켜주는 코드
  //--------
  for (let i = 0; i < 51; i++) {
    a[i].fill(0);
    visited[i].fill(false);
  }
  ret = 0;
  //--------
  const parts = readLine().split(' ').map(Number);
  m = parts[0]; n = parts[1]; k = parts[2];
  for (let i = 0; i < k; i++) {
    const [tx, ty] = readLine().split(' ').map(Number);
    a[ty][tx] = 1;
  }
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (a[i][j] === 1 && !visited[i][j]) {
        dfs(i, j);
        ret++;
      }
    }
  }
  console.log(ret);
}
