// beakjoon 2852 - NBA 농구 경기
// cpp 코드를 자바스크립트로 옮긴 것

const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const n = Number(input[0]);

// "MM:SS" -> 초
function changeToInt(s) {
  return Number(s.slice(0, 2)) * 60 + Number(s.slice(3, 5));
}

// 초 -> "MM:SS"
function print(a) {
  const m = String(Math.floor(a / 60)).padStart(2, '0');
  const s = String(a % 60).padStart(2, '0');
  return `${m}:${s}`;
}

let A = 0;
let B = 0;
let asum = 0;
let bsum = 0;
let prev = 0; // 직전 이벤트 시각(초), 시작은 00:00

for (let i = 0; i < n; i++) {
  const [oStr, s] = input[i + 1].split(' ');
  const cur = changeToInt(s);

  if (A > B) asum += cur - prev;
  else if (B > A) bsum += cur - prev;

  if (oStr === '1') A++;
  else B++;

  prev = cur;
}

const end = 48 * 60; // 48:00
if (A > B) asum += end - prev;
else if (B > A) bsum += end - prev;

console.log(print(asum));
console.log(print(bsum));
