const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const a = Array.from({ length: 101 }, () => Array(101).fill(0));
const visited = Array.from({ length: 101 }, () => Array(101).fill(0));
let n, ret = 1;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

function dfs(y, x, d) {
  visited[y][x] = 1;
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n)
      continue;
    if (!visited[ny][nx] && a[ny][nx] > d)
      dfs(ny, nx, d);
  }
  return;
}

// 왜 이런 작업들이 들어가는지 한번 더 집고 넘어가자

n = Number(readLine());
for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < n; j++) {
    a[i][j] = row[j];
  }
}

// d(비가 오는 범위)가 100까지 될 수 있다고 했으니, 101 전까지 최상위에서 루프를 돌렸어야함
for (let d = 1; d < 101; d++) {
  // 테스트 케이스 100번을 돌때마다 visited 를 초기화 시킨다.
  for (let i = 0; i < 101; i++) visited[i].fill(0);
  let cnt = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (a[i][j] > d && !visited[i][j]) {
        dfs(i, j, d);
        cnt++;
      }
    }
  }
  // 최대값을 구하기 위함
  ret = Math.max(ret, cnt);
}
console.log(ret);
