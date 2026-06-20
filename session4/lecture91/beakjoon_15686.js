// https://www.acmicpc.net/problem/15686

const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const [n, m] = readLine().split(' ').map(Number);
const a = [];
const _home = [];
const chicken = [];
const chickenList = [];
let result = 987654321;

function combi(start, v) {
  if (v.length === m) {
    // 조합을 통한 로직!
    chickenList.push([...v]);
    return;
  }
  for (let i = start + 1; i < chicken.length; i++) {
    v.push(i);
    combi(i, v);
    v.pop();
  }
}

// 1단계 무식하게 풀수 있는지 가늠을 해본다!

// 조합의 연산을 쉽게 하기 위해, 2차원 배열로 입력값을 넣어둔다
// 인덱스를 기반으로 데이터를 다루기 위함
for (let i = 0; i < n; i++) {
  const row = readLine().split(' ').map(Number);
  a.push(row);
  for (let j = 0; j < n; j++) {
    if (a[i][j] === 1) _home.push([i, j]);
    if (a[i][j] === 2) chicken.push([i, j]);
  }
}

combi(-1, []);

// 조합을 통해 얻은 가공된 데이터 chickenList를 가지고 무식하게 문제를 풀기위한 완전탐색을 진행한다.
for (const cList of chickenList) {
  let ret = 0;
  for (const home of _home) {
    // 일부러 큰값을 준다.
    let _min = 987654321;
    for (const ch of cList) {
      const _dist = Math.abs(home[0] - chicken[ch][0]) + Math.abs(home[1] - chicken[ch][1]);
      _min = Math.min(_min, _dist);
    }
    ret += _min;
  }
  result = Math.min(result, ret);
}
console.log(result);
