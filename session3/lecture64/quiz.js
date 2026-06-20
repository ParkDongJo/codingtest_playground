const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

/*
[문제]
승원이는 당근을 좋아해서 당근마킷에 엔지니어로 취업했다. 당근을 매우좋아하기 때문에 차도
당근차를 샀다. 이 당근차는 한칸 움직일 때마다 당근을 내뿜으면서 간다. 즉,
"한칸" 움직일 때
"당근한개"가 소모된다는 것이다. 승원이는 오늘도 아침 9시에 일어나 당근마킷으로 출근하고자
한다. 승원이는 최단거리로 당근마킷으로 향한다고 할 때 당근몇개를 소모해야 당근마킷에 갈 수
있는지 알아보자. 이 때 승원이는 육지로만 갈 수 있으며 바다로는 못간다. 맵의 1은 육지며 0은
바다를 가리킨다. 승원이는 상하좌우로만 갈 수 있다.

[입력]
맵의 세로길이 N과 가로길이 M 이 주어지고 이어서 N * M의 맵이 주어진다. 그 다음 줄에 승원이의
위치(y, x)와 당근마킷의 위치(y, x)가 주어진다. 이 때 승원이의 시작위치(y, x)에서 "당근한개"가
이미 소모된 상태로 본다.

[출력]
당근을 몇개 소모해야 하는지 출력하라.

[범위]
1 <= N <= 100
1 <= M <= 100

[예제입력]
5 5
0 0
4 4
1 0 1 0 1
1 1 1 0 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
[예제출력]
9

*/

const max_n = 104;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
const a = Array.from({ length: max_n }, () => Array(max_n).fill(0));
const visited = Array.from({ length: max_n }, () => Array(max_n).fill(0));
let y, x;

// scanf vs. cin 둘중에 뭐든 상관없지만, 쓸거면 하나만 쓰자!!
const [n, m] = readLine().split(' ').map(Number);
const [sy, sx] = readLine().split(' ').map(Number);
const [ey, ex] = readLine().split(' ').map(Number);

for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  for (let j = 0; j < m; j++) {
    a[i][j] = row[j];
  }
}

// 2차원 좌표이기 때문에!
const q = [[sy, sx]];
let qi = 0;

// 첫 시작지점은 체크를 해준다
visited[sy][sx] = 1;

while (qi < q.length) {
  const [y, x] = q[qi++];
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    // 더이상 갈수 없는 바다라면
    if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] === 0)
      continue;

    // 이미 방문을 한 지점이라면
    if (visited[ny][nx])
      continue;

    visited[ny][nx] = visited[y][x] + 1;
    q.push([ny, nx]);
  }
}
console.log(visited[ey][ex]);

// 최단거리 디버깅
for (let i = 0; i < n; i++) {
  let row = '';
  for (let j = 0; j < m; j++) {
    row += visited[i][j] + ' ';
  }
  console.log(row);
}
