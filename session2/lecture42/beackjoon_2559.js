const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

// 연속의 온도의 합이 "최대" 되느니 값
//  = 구간합 prefix sum, psum[i] = psum[i - 1] + a[i]

// 최대값
// = 최솟갑 ~ 최대값
// = max(ret, value)
// 최소값
// = 최대값 ~ 최소값
// = min(ret, value)

const [n, k] = readLine().split(' ').map(Number);
const psum = new Array(n + 1).fill(0);
const temps = readLine().split(' ').map(Number);

for (let i = 0; i < n; i++) {
  psum[i + 1] = psum[i] + temps[i];
}

let ret = -10000004;
for (let i = k; i <= n; i++) {
  ret = Math.max(ret, psum[i] - psum[i - k]);
}

console.log(ret);
