const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const s = readLine().split('').sort().join('');
let head = '';
let tail = '';
let mid = '';

let count = 0;
for (let i = 0; i < s.length; i++) {
  if (i / 2 === 0) {
    head += s[i];
  } else {
    if (head[head.length - 1] === s[i]) {
      tail + s[i];
    }
    // 여기서 꼬임
    else {
      count++;
      if (count > 1) {
        console.log("I'm Sorry Hansoo");
        process.exit(0);
      } else {
        mid = s[i];
      }
    }
  }
}
console.log(head + mid + tail);

// 테스트 자동화
