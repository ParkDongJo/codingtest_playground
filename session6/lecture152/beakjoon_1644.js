const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = Number(readLine());
const che = new Array(4000001).fill(false);
const a = [];
let lo = 0, hi = 0, ret = 0, sum = 0;

// 에라토스테네스체 를 만드는 과정
for (let i = 2; i <= n; i++) {
  if (che[i]) continue;
  for (let j = 2 * i; j <= n; j += i) {
    che[j] = true;
  }
}
for (let i = 2; i <= n; i++) {
  if (!che[i])
    a.push(i);
}

const p = a.length;

// 투포인터 과정
while (true) {
  if (sum >= n)
    sum -= a[lo++];
  //  high 와 p(소수의 개수) 가 같다면, 루프를 빠져나온다.
  else if (hi === p)
    break;
  else
    sum += a[hi++];
  if (sum === n)
    ret++;
}
console.log(ret);
