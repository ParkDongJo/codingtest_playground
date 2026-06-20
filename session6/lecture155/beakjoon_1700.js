const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const [n, k] = readLine().split(' ').map(Number);
const a = readLine().split(' ').map(Number);

const plug = new Set();
let count = 0;

for (let i = 0; i < k; i++) {
  if (plug.has(a[i])) continue;

  if (plug.size < n) {
    plug.add(a[i]);
    continue;
  }

  // 멀티탭이 가득 찬 경우: 가장 나중에 사용되는 것을 뺀다
  let target = -1;
  let farthest = -1;

  for (const p of plug) {
    let nextUse = Infinity;
    for (let j = i + 1; j < k; j++) {
      if (a[j] === p) {
        nextUse = j;
        break;
      }
    }
    if (nextUse > farthest) {
      farthest = nextUse;
      target = p;
    }
  }

  plug.delete(target);
  plug.add(a[i]);
  count++;
}

console.log(count);
