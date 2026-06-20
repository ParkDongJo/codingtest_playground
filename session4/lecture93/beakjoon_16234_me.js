const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const len = 51;
const [n, l, r] = readLine().split(' ').map(Number);

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let visited = Array.from({ length: len }, () => Array(len).fill(0));
const ground = [];
for (let i = 0; i < n; i++) {
  ground.push(readLine().split(' ').map(Number));
}

let people_sum = 0;
let cnt = 0;
let temp = 0;

function dfs_for_check(y, x) {
  visited[y][x] = 1;

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
    if (visited[ny][nx] !== 0) continue;
    if (ground[ny][nx] < l && ground[ny][nx] > r) continue;

    visited[ny][nx] = 1;
    people_sum += ground[ny][nx];
    cnt++;
    dfs_for_check(ny, nx);
  }
}

function dfs_for_inject(y, x) {
  visited[y][x] = 1;

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
    if (visited[ny][nx] === 0) continue;

    ground[ny][nx] = temp;
    dfs_for_inject(ny, nx);
  }
}

let flag = true;
// 끝날때까지 계속 돈다면, while 로 제어!
while (flag) {
  // 초기화
  people_sum = 0;
  cnt = 0;
  visited = Array.from({ length: len }, () => Array(len).fill(0));

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (visited[i][j] !== 1) {
        dfs_for_check(i, j);
        temp = Math.floor(people_sum / cnt);
      }
    }
  }

  if (cnt === 0) {
    flag = false;
  }

  // 초기화
  visited = Array.from({ length: len }, () => Array(len).fill(0));

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (visited[i][j] === 1) {
        dfs_for_inject(i, j);
      }
    }
  }
}
