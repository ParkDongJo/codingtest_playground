const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const totalLines = [];
let result = 0;

const n = Number(readLine());

for (let i = 0; i < n; i++) {
  const [from, to] = readLine().split(' ').map(Number);
  totalLines.push([from, to]);
}
totalLines.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
let front = totalLines[0][0];
let tail = totalLines[0][1];

for (let i = 1; i < n; i++) {
  // 겹치지 않는 경우 tail, front 를 갱신
  if (result < totalLines[i][0]) {
    // 길이를 더한다.
    result += (tail - front);

    // 새로운 선의 front, tail 을 설정한다.
    front = totalLines[i][0];
    tail = totalLines[i][1];
  }
  // 겹치는 경우, tail 만 갱신
  else if (totalLines[i][0] <= front && totalLines[i][1] >= tail) {
    tail = totalLines[i][1];
  }
}
result += (tail - front);
console.log(result);
