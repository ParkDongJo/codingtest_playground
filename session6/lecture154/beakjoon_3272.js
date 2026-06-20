const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = Number(readLine());
const a = readLine().split(' ').map(Number);
const x = Number(readLine());

a.sort((a, b) => a - b);

let left = 0, right = n - 1;
let count = 0;

while (left < right) {
  if (a[left] + a[right] === x) {
    count++;
    left++;
    right--;
  } else if (a[left] + a[right] < x) {
    left++;
  } else {
    right--;
  }
}
console.log(count);