const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = parseInt(readLine());
let ret = 0;

for (let i = 0; i < n; i++) {
  const s = readLine();
  const stk = [];

  for (const a of s) {
    if (stk.length && stk[stk.length - 1] === a)
      stk.pop();
    else
      stk.push(a);
  }
  if (stk.length === 0)
    ret++;
}

console.log(ret);
