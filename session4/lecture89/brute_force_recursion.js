const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = Number(readLine());
const v = readLine().split(' ').map(Number);

// 소수를 판별하는 함수
function check(sum) {
  if (sum <= 1) return 0;
  if (sum === 2) return 1;
  // 짝수는 소수가 아니다
  if (sum % 2 === 0) return 0;
  for (let i = 2; i * i <= sum; i++) {
    // 모듈러 연산으로 해서 나머지가 0이면 소수가 아니다
    if (sum % i === 0) return 0;
  }
  // 지금까지의 조건을 다 만족하면 소수다
  return 1;
}

function go(idx, sum) {
  if (idx === n) {
    return check(sum);
  }
  return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}

console.log(go(0, 0));
