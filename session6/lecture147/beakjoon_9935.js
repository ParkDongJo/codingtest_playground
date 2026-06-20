const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const S = readLine();
const T = readLine();
let ret = '';
const stk = [];

for (const a of S) {
  stk.push(a);
  if (stk.length >= T.length && stk[stk.length - 1] === T[T.length - 1]) {
    let ss = '';
    for (let j = 0; j < T.length; j++) {
      ss += stk.pop();
    }
    ss = ss.split('').reverse().join('');
    if (T !== ss) {
      // 다시 넣어준다.
      for (const c of ss) {
        stk.push(c);
      }
    }
  }
}
if (stk.length === 0) {
  console.log("FRULA");
} else {
  // 스텍 사이즈 만큼 꺼내서 뒤집어서 넣어준다.
  // (JS array acts as stack but maintains order, so just join)
  console.log(stk.join(''));
}
