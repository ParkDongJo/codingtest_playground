const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(/\s+/);

let n;
let a = [];
let check = new Array(10).fill(false);
let ret = [];

function good(x, y, op) {
  if (op === '<') return x < y;
  else return x > y;
}

function go(idx, num) {
  
  if (idx === n + 1) {
    ret.push(num);
    return;
  }
  for (let i = 0; i < 10; i++) {
    // 이미 사용한 숫자라면 건너뛴다.
    if (check[i]) continue;
    // idx가 0이라면 어떤 숫자든 올 수 있다.
    // idx가 0이 아니라면, num의 마지막 숫자와 i 사이에 관계가 성립하는지 확인한다.
    if (idx === 0 || good(num[idx - 1], String(i), a[idx - 1])) {
      check[i] = true;
      go(idx + 1, num + String(i));
      check[i] = false;
    }
  }
}

n = parseInt(input[0], 10);
for (let i = 0; i < n; i++) {
  a[i] = input[i + 1];
}

go(0, "");

ret.sort();

console.log(ret[ret.length - 1] + "\n" + ret[0]);
