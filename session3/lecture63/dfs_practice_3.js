const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const max_n = 104;

let n, m;

const arr = Array.from({ length: max_n }, () => Array(max_n).fill(0));
const visited = Array.from({ length: max_n }, () => Array(max_n).fill(0));

/*
     0,1
-1,0  0  1,0
    0,-1
*/

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let result = 0;

function dfs(y, x) {
  visited[y][x] = 1;

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] === 0)
      continue;
    if (visited[ny][nx] === 1)
      continue;
    dfs(ny, nx);
  }
}

const [N, M] = readLine().split(' ').map(Number);
n = N;
m = M;
for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < m; j++) {
    arr[i][j] = row[j];
  }
}

// dfs
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    // 여기서 1을 체크한건 문제의 특성상!
    if (arr[i][j] === 1 && !visited[i][j]) {
      dfs(i, j);
      result++;
    }
  }
}

console.log(result);
