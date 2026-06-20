const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(/\s+/);

const n = parseInt(input[0], 10);
const ops = input.slice(1, n + 1);

const used = new Array(10).fill(false);
const results = [];

// op 기준 a, b 부등호 관계 검사
function satisfies(a, b, op) {
  return op === '<' ? a < b : a > b;
}

// idx 자리에 숫자를 채워가며 n+1자리 수 완성
function dfs(idx, num) {
  if (idx === n + 1) {
    results.push(num);
    return;
  }
  for (let i = 0; i < 10; i++) {
    if (used[i]) continue;
    if (idx === 0 || satisfies(num[idx - 1], String(i), ops[idx - 1])) {
      used[i] = true;
      dfs(idx + 1, num + String(i));
      used[i] = false;
    }
  }
}

dfs(0, "");
results.sort();

console.log(results[results.length - 1] + "\n" + results[0]);
