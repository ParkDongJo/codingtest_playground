const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const n = Number(readLine());

// vector<pair<int,int>> a 에 n 숫자를 지정해서 크기를 정할 수 있다.
const a = [];

for (let i = 0; i < n; i++) {
  // vector 에 바로 입력할 수도 있다.
  const [first, second] = readLine().split(' ').map(Number);
  a.push([first, second]);
}

a.sort((x, y) => x[0] - y[0] || x[1] - y[1]);

let realTime = a[0][0] + a[0][1];

for (let i = 1; i < a.length; i++) {
  // 계속해서 max 를 갱신해 간다.
  // 이렇게 하면 둘을 비교할 필요 없이 아래와 같이 하면 된다.
  realTime = Math.max(realTime, a[i][0]);
  realTime += a[i][1];
}

console.log(realTime);
