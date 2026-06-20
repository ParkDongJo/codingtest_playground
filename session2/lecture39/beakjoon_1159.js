const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = parseInt(readLine());
const cnt = new Array(26).fill(0);

for (let i = 0; i < n; i++) {
  const s = readLine();
  cnt[s.charCodeAt(0) - 'a'.charCodeAt(0)]++;
}

let ret = '';
for (let i = 0; i < 26; i++) {
  if (cnt[i] >= 5) {
    // a + 0 = 97 = a
    // a + 1 = 98 = b
    ret += String.fromCharCode(i + 'a'.charCodeAt(0));
  }
}

if (ret.length)
  console.log(ret);
else
  console.log('PREDAJA');
