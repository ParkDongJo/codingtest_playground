const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = Number(readLine());
const v = readLine().split(' ').map(Number);

let ret = 0;
let cnt = 0;
const mod = 11;

function go(idx, sum) {
  if (idx === n) {
    // 보통 완전탐색에서 재귀를 쓸땐
    // 기저사례에서 원하는 로직을 구현한다
    ret = Math.max(ret, sum % mod);
    cnt++;
    return;
  }
  go(idx + 1, sum + v[idx]);
  go(idx + 1, sum);
}

// 만약 문제에서 최대값을 구하라고 했으면 -> 최소값부터 시작해야한다
// 반대로 최소값을 구하라고 했으면 -> 최대값부터 시작해야한다
// 더 중요한건 이 초기값은 답의 범위가 될 수 없는 가장 최소값(최대값)이어야 한다.
go(0, 0);

console.log(ret);
console.log(cnt);
