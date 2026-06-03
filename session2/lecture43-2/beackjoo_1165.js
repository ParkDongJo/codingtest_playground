const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

// 공간의 버퍼를 두기위해 100000 만큼만 넣는게 아니라, 100004 로 약간 버퍼를 두면,
// 나중에 약간의 연산 차이를 놓쳤을때, 헤매지 않을 수 있다.

// --------------------
// 입출력 속도 향상을 위해 사용하는 코드
// --------------------

const [n, m] = readLine().split(' ').map(Number);
const mp = {};
const mp2 = {};

for (let i = 0; i < n; i++) {
  const s = readLine();
  mp[s] = i + 1;
  mp2[i + 1] = s;
}

const results = [];
for (let i = 0; i < m; i++) {
  const s = readLine();
  if (parseInt(s) === 0 || isNaN(parseInt(s))) {
    // 이건 왜?
    results.push(mp[s]);
  } else {
    results.push(mp2[parseInt(s)]); // 포켓몬 번호
  }
}

console.log(results.join('\n'));
