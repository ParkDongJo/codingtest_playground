const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let ret = 0;

// 이건 왜?
const n = Number(readLine());
const v = [];

for (let i = 0; i < n; i++) {
  const [front, tail] = readLine().split(' ').map(Number);
  v.push([front, tail]);
}

v.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

let curr_end = v[0][1];
for (let i = 1; i < n; i++) {
  if (v[i][0] < curr_end) {
    continue;
  }
  curr_end = v[i][1];
  ret++;
}

console.log(ret);
