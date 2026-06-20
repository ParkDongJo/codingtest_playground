const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = Number(readLine());
const v = readLine().split(' ').map(Number);

let ret = 0;
let cnt = 0;
const mod = 11;

function go(idx, sum) {
  // 벡트레킹 가지치기!!!
  if (ret === mod - 1) return;
  if (idx === n) {
    ret = Math.max(ret, sum % mod);
    cnt++;
    return;
  }
  go(idx + 1, sum + v[idx]);
  go(idx + 1, sum);
}

go(0, 0);

console.log(ret);
console.log(cnt);
