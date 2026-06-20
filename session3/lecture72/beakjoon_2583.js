const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const a = Array.from({ length: 104 }, () => Array(104).fill(0));
let m, n, k, x1, x2, y1, y2;
const visited = Array.from({ length: 104 }, () => Array(104).fill(0));
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
const ret = [];

// 그리고 int 형 dfs 로 dfs 를 하면서 그 갯수를 재귀로 더해가는 걸 생각해내는게 핵심이다
function dfs(y, x) {
  visited[y][x] = 1;
  let ret = 1;
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] === 1)
      continue;
    if (a[ny][nx] === 1)
      continue;

    // 탐색을 하게 되면 칸 갯수를 +1 씩 한다.
    ret += dfs(ny, nx);
  }
  return ret;
}

const parts = readLine().split(' ').map(Number);
m = parts[0]; n = parts[1]; k = parts[2];

for (let i = 0; i < k; i++) {
  const [tx1, ty1, tx2, ty2] = readLine().split(' ').map(Number);
  x1 = tx1; y1 = ty1; x2 = tx2; y2 = ty2;

  // 입력을 받자마자 바로 만든다..
  // 나는 포지션에 넣었다가, 그걸 또 다시 꺼내는 방향으로 생각했는데
  // 그러다보니 담는 자료구조, 꺼내서 다시 담는 자료구조 등등의 구조 복잡도가 증가해서 생각이 꼬였는데...
  // 그냥 입력 받자마자 바로 그 해당 구조에 넣는 방법으로 하니 훨씬 생각이 편하다
  for (let x = x1; x < x2; x++) {
    for (let y = y1; y < y2; y++) {
      a[y][x] = 1;
    }
  }
}

// 그리고 그 구조를 탐색하면서 갯수를 체크한다.
for (let i = 0; i < m; i++) {
  for (let j = 0; j < n; j++) {
    if (a[i][j] !== 1 && visited[i][j] === 0) {
      ret.push(dfs(i, j));
    }
  }
}

// 결과를 크기순으로 정렬하고
ret.sort((a, b) => a - b);

// 결과를 출력한다
console.log(ret.length);
console.log(ret.join(' '));
