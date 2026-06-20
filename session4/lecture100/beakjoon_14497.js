const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const [n, m] = readLine().split(' ').map(Number);
let [y1, x1, y2, x2] = readLine().split(' ').map(Number);
y1--; x1--; y2--; x2--;

const a = [];
for (let i = 0; i < n; i++) {
  a.push(readLine().split(''));
}

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
const visited = Array.from({ length: n }, () => Array(m).fill(0));

let q = [[y1, x1]];
visited[y1][x1] = 1;
let cnt = 0;

while (a[y2][x2] !== '0') {
  cnt++;
  const temp = [];
  let qi = 0;
  while (qi < q.length) {
    const [y, x] = q[qi++];
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
      visited[ny][nx] = cnt;
      if (a[ny][nx] !== '0') {
        a[ny][nx] = '0';
        temp.push([ny, nx]);
      } else {
        q.push([ny, nx]);
      }
    }
  }
  q = temp;
}

console.log(visited[y2][x2]);
