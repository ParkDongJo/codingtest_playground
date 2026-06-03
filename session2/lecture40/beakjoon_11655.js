const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

// 띄워쓰기 까지 문자열을 받기위해
let s = readLine().split('');

for (let i = 0; i < s.length; i++) {
  const code = s[i].charCodeAt(0);
  if (code >= 65 && code < 97) {
    if (code + 13 > 90) {
      s[i] = String.fromCharCode(code + 13 - 26);
    } else {
      s[i] = String.fromCharCode(code + 13);
    }
  } else if (code >= 97 && code <= 122) {
    if (code + 13 > 122) {
      s[i] = String.fromCharCode(code + 13 - 26);
    } else {
      s[i] = String.fromCharCode(code + 13);
    }
  }
}

console.log(s.join(''));
