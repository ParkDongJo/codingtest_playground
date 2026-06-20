const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const max_len = 104;
let m, n, ny, nx;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
const visited = Array.from({ length: max_len }, () => Array(max_len).fill(false));
const ground = Array.from({ length: max_len }, () => Array(max_len).fill(0));
let cnt = 0, cnt_max;

function dfs(y, x, k) {
  visited[y][x] = true;

  for (let i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx > m) {
      continue;
    }
    if (ground[ny][nx] < k && visited[ny][nx] !== false) {
      continue;
    }
    dfs(ny, nx, k);
    cnt++;
  }
}

n = Number(readLine());

for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < n; j++) {
    ground[i][j] = row[j];
  }
}

for (let k = 0; k < n; k++) {
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (ground[i][j] > k && visited[i][j] !== false) {
        dfs(i, j, k);
        cnt_max = cnt;
        cnt = 0;
      }
    }
  }
}

console.log(cnt_max);
