const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = 3;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const arr = Array.from({ length: n }, () => Array(n).fill(0));
const visited = Array.from({ length: n }, () => Array(n).fill(0));

/*
Q)

3 * 3 맵을 입력받아야 함. 이 맵은 1과 0으로 이루어져있고 {0, 0}은
무조건 1임을 보장한다. {0, 0}부터 4방향을 기준으로 한칸씩 탐색해나가며
방문한 정점은 다시 방문하지 않으며 방문하는 좌표
를 출력하는 코드. 0은 갈
수 없는 지역. 1은 갈 수 있는 지역을
구현하시오.

*/

function visit(y, x) {
  visited[y][x] = 1;

  for (let i = 0; i < 4; i++) {
    const nextY = y + dy[i];
    const nextX = x + dx[i];

    // 범위를 벗어날 때는 그냥 넘어가라
    if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
      continue;

    // 갈수 없는 지역에 대해서는 그냥 넘어가라
    if (arr[nextY][nextX] === 0)
      continue;

    // 곧 탐색할 정점이 이미 방문을 한 정점이라면 그냥 넘어가라
    if (visited[nextY][nextX])
      continue;

    visit(nextX, nextY);
  }
  return;
}

// 행렬을 입력 받는다고 했을때
for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < n; j++) {
    arr[i][j] = row[j];
  }
}
visit(0, 0);
