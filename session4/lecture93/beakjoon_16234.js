const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const [n, l, r] = readLine().split(' ').map(Number);
const a = [];
for (let i = 0; i < n; i++) {
  a.push(readLine().split(' ').map(Number));
}

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

// 연산을 해야하는 좌표 집합
let v = [];
let visited;
let sum = 0;
let cnt = 0;

function dfs(y, x) {
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx])
      continue;

    // abs 로 절대값에 대한 계산
    // 소수점 제거라고 했을 시 사용
    if (Math.abs(a[ny][nx] - a[y][x]) >= l && Math.abs(a[ny][nx] - a[y][x]) <= r) {
      visited[ny][nx] = 1;
      // 좌표 넣고
      v.push([ny, nx]);
      // 인구합
      sum += a[ny][nx];
      dfs(ny, nx);
    }
  }
}

while (true) {
  // flag 를 false 부터 시작
  let flag = false;
  // 초기화
  visited = Array.from({ length: 54 }, () => Array(54).fill(0));
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      // 방문할 것이 더이상 없다면,
      // 최상위 루프를 벗어나아함
      if (!visited[i][j]) {
        // 좌표 초기화
        v = [];
        visited[i][j] = 1;
        // 좌표 넣기
        v.push([i, j]);
        // 인구 합
        sum = a[i][j];

        dfs(i, j);
        if (v.length === 1) continue;

        // 인구 주입
        for (const b of v) {
          a[b[0]][b[1]] = Math.floor(sum / v.length);
          // 주입을 하고 나서는 한번 더 돌게끔 flag true
          flag = true;
        }
      }
    }
  }
  if (!flag) break;
  cnt++;
}
console.log(cnt);
