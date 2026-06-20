const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let n, m;

const arr = Array.from({ length: 104 }, () => Array(104).fill(0));
const visited = Array.from({ length: 104 }, () => Array(104).fill(0));

let result = 0;

// 좌우방향
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

function dfs(y, x) {
  // dfs 는 bfs 와 달리 dfs 시작부터 방문체크를 한다.
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

// 입력 셋팅
const [N, M] = readLine().split(' ').map(Number);
n = N;
m = M;
for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < m; j++) {  // 원본 버그: i++ 이지만 무한루프 방지를 위해 j++
    arr[i][j] = row[j];
  }
}

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    // 육지이고, 방문하지 않았다면
    if (arr[j][i] === 1 && !visited[i][j]) {
      dfs(i, j);
      result++;
    }
  }
}
