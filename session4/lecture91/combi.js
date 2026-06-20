const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const [n, m] = readLine().split(' ').map(Number);
const vList = [];

function combi(start, v) {
  if (v.length === m) {
    vList.push([...v]);
    return;
  }
  for (let i = start + 1; i < n; i++) {
    v.push(i);
    combi(i, v);
    v.pop();
  }
}

combi(-1, []);
