const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

// 근데 이게 그리디랑 뭔 관계지?
const lineStr = readLine();
const bomb = readLine();
let result = lineStr;

while (true) {
  // find() 함수가 bomb 을 찾지 못하면 -1 을 반환한다.
  // 즉 아래 조건문은 bomb 를 line 에서 찾았다는 의미이다.
  const idx = result.indexOf(bomb);
  if (idx !== -1) {
    // find() 함수는 찾으면 index 를 반환한다.
    // 즉 아래 코드는 bomb 의 크기만큼 line 에서 제거한다.
    result = result.substring(0, idx) + result.substring(idx + bomb.length);
  } else {
    // 못찾으면 반복문을 중단한다.
    break;
  }
}
if (result.length === 0) {
  console.log("FRULA");
}
console.log(result);
