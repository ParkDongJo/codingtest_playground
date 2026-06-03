const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const s = readLine();

// 글자를 카운팅 한다
const cnt = new Array(200).fill(0);
for (const c of s) {
  cnt[c.charCodeAt(0)]++;
}

let flag = 0;
let mid = '';
let ret = '';

// 글자를 역순으로 확인한다
for (let i = 'Z'.charCodeAt(0); i >= 'A'.charCodeAt(0); i--) {
  // 글자가 홀수인 경우
  if (cnt[i] & 1) {
    // 중앙 글자를 설정한다
    mid = String.fromCharCode(i);
    // 중앙 글자를 카운팅 한다
    flag++;
    // 글자를 카운팅 한다
    cnt[i]--;
  }
  // 중앙 글자가 2개 이상인 경우 종료
  if (flag === 2) break;

  // 글자를 2개씩 추가한다
  for (let j = 0; j < cnt[i]; j += 2) {
    // 글자를 앞에서부터 추가한다
    ret = String.fromCharCode(i) + ret;
    // 글자를 뒤에서부터 추가한다
    ret += String.fromCharCode(i);
  }
}

// 중앙 글자가 있는 경우 추가한다
if (mid) {
  const half = Math.floor(ret.length / 2);
  ret = ret.slice(0, half) + mid + ret.slice(half);
}

// 중앙 글자가 2개 이상인 경우 종료
if (flag === 2)
  console.log("I'm Sorry Hansoo");
// 중앙 글자가 없는 경우 출력한다
else
  console.log(ret);
