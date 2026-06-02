const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const s = readLine();
const temp = s.split('').reverse().join('');

if (temp === s)
  console.log(1);
else
  console.log(0);
