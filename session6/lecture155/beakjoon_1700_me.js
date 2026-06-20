const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const [n, k] = readLine().split(' ').map(Number);
const a = readLine().split(' ').map(Number);

a.sort((a, b) => a - b);

const stack = [];

for (let i = 0; i < k; i++) {
  if (stack.length < n) {
    stack.push(a[i]);
  } else {
    if (stack[stack.length - 1] === a[i]) {
      stack.pop();
    } else {
      stack.push(a[i]);
    }
  }
}

console.log(stack.length - n);
