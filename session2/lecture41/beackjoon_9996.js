const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = parseInt(readLine());
const ori_s = readLine();
const pos = ori_s.indexOf('*');
const pre = ori_s.slice(0, pos);
const suf = ori_s.slice(pos + 1);

for (let i = 0; i < n; i++) {
  const s = readLine();
  if (pre.length + suf.length > s.length) {
    console.log('NE');
  } else {
    if (s.slice(0, pre.length) === pre && s.slice(s.length - suf.length) === suf)
      console.log('DA');
    else
      console.log('NE');
  }
}
