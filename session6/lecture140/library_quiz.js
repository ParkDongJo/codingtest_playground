const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let idx = 0, ret = 1;

const n = Number(readLine());
const v = [];

for (let i = 0; i < n; i++) {
  const [from, to] = readLine().split(' ').map(Number);
  v.push([to, from]);
}

// start 를 기준으로 정렬하기 때문에, 여기서는 to 데이터를 기준으로 정렬함
v.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
let from = v[0][1];
let to = v[0][0];

for (let i = 0; i < n; i++) {
  // 이전 종료시간보다 시작시간이 빠르면 패스
  if (v[i][1] < to) {
    continue;
  }
  from = v[i][1];
  to = v[i][0];
  // 이전 종료시간보다 시작시간이 늦으면 카운트 증가
  ret++;
}

console.log(ret);
