const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = Number(readLine());
const lineArr = [];

for (let i = 0; i < n; i++) {
  const [from, dist] = readLine().split(' ').map(Number);
  lineArr.push([from, dist]);
}

lineArr.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

for (let i = 0; i < n - 1; i++) {
  const to = lineArr[i][0] + lineArr[i][1];

  if (to > lineArr[i + 1][0]) {
    lineArr[i + 1][0] = to;
  }
}

console.log(lineArr[n - 1][0] + lineArr[n - 1][1]);
