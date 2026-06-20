const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const max_size = 104;

const arr = Array.from({ length: max_size }, () => Array(max_size).fill(0));
const visited = Array.from({ length: max_size }, () => Array(max_size).fill(0));
const p = [];

let n, m, k;
let y1, x1, y2, x2;

function dfs(y, x) {
}

// 입력을 받고
const parts = readLine().split(' ').map(Number);
n = parts[0]; m = parts[1]; k = parts[2];

for (let i = 0; i < k; i++) {
  const [tx1, ty1, tx2, ty2] = readLine().split(' ').map(Number);
  p.push([[tx1, ty1], [tx2, ty2]]);
}

// 자료구조를 만들고
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    arr[j][i] = 0;
  }
}

// 직사각형 그리기

// 빈공간 갯수 세기
