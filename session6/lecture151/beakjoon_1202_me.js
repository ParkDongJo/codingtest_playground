const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let ret = 0;

const [n, k] = readLine().split(' ').map(Number);

const temps = [];
const bags = [];

for (let i = 0; i < n; i++) {
  const [m, v] = readLine().split(' ').map(Number);
  temps.push([m, v]);
}

const c = Number(readLine());

for (const t of temps) {
  if (t[0] <= c) {
    bags.push(t);
  }
}

bags.sort((a, b) => a[1] - b[1]);

for (let i = 0; i < c; i++) {
  ret += bags[i][1];
}
console.log(ret);
