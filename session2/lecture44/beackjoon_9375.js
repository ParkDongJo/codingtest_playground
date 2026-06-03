const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const t = parseInt(readLine());

for (let tc = 0; tc < t; tc++) {
  const n = parseInt(readLine());
  const mp = {};

  for (let i = 0; i < n; i++) {
    const [a, b] = readLine().split(' ');
    mp[b] = (mp[b] || 0) + 1;
  }

  // 경우의 수 같은 경우는 숫자가 커질 수 있기 때문에, long long 박아두고 문제를 푸는 것이 좋다
  let ret = 1;
  for (const key of Object.keys(mp)) {
    // 종류마다 아무것도 안입은 경우를 +1 해준다.
    ret *= (mp[key] + 1);
  }
  // 아무것도 안입은 경우
  ret--;
  console.log(ret);
}
