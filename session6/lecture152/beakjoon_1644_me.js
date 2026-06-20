const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let ret = 0, sum = 0;
const v = [];

// 소수를 판별하는 함수
function isPrime(n) {
  if (n <= 1) return false;
  for (let i = 2; i * i <= n; i++) {
    if (n % i === 0) return false;
  }
  return true;
}

const n = Number(readLine());

for (let i = 2; i <= n; i++) {
  if (isPrime(i))
    v.push(i);
}

let left = 0, right = 0;

while (left < v.length && right < v.length) {
  if (sum < n)
    sum += v[right++];
  else if (sum > n)
    sum -= v[left++];
  else if (sum === n) {
    ret++;
    sum += v[right++];
  }
}

console.log(ret);
