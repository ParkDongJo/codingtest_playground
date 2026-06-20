const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const max_n = 104;
let n, m, startY, startX, endY, endX;

// 좌우 방향
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const arr = Array.from({ length: max_n }, () => Array(max_n).fill(0));
const visited = Array.from({ length: max_n }, () => Array(max_n).fill(0));

const [N, M] = readLine().split(' ').map(Number);
n = N; m = M;
const [SY, SX] = readLine().split(' ').map(Number);
startY = SY; startX = SX;
const [EY, EX] = readLine().split(' ').map(Number);
endY = EY; endX = EX;

// 입력값 셋팅 완료
for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < m; j++) {
    arr[i][j] = row[j];
  }
}

// 최초 방문체크
visited[startY][startX] = 1;

const q = [[startY, startX]];
let qi = 0;

while (qi < q.length) {
  const [qy, qx] = q[qi++];

  for (let i = 0; i < 4; i++) {
    const nextY = qy + dy[i];
    const nextX = qx + dx[i];

    if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || arr[nextY][nextX] === 0) {
      continue;
    }
    if (visited[nextY][nextX]) {
      continue;
    }

    // dfs 는 bfs 와 달리 dfs 모든 사전조건을 피했을 때, 방문체크를 한다

    visited[nextY][nextX] = visited[qy][qx] + 1;
    q.push([nextY, nextX]);
  }
}
