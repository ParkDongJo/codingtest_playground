const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let cnt = 0;

// 1e7 = 백만
const INF = 1e7;

const n = Number(readLine());

for (let i = 0; i < INF; i++) {
  const a = String(i);
  // string::npos = 문자열을 찾을 수 없는 경우
  if (a.indexOf("240") !== -1) {
    cnt++;
    if (n === cnt) {
      console.log(a);
      break;
    }
  }
}
