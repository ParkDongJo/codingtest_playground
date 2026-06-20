const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

while (line < input.length) {
  const n = parseInt(readLine());
  let cnt = 1;
  let ret = 1;

  while (true) {
    if (cnt % n === 0) {
      console.log(ret);
      // flag 를 줄 필요 없이 break 를 활용하자!
      // 알고리즘 문제 풀땐.. 이게 더 좋을것 같다!
      break;
    } else {
      // 이전 계산에 대한 결과를 그대로 사용하면 더 빠르다.
      cnt = (cnt * 10) + 1;
      // 정수 모듈연산의 법칙을 적용하면 더 빠르다.
      cnt %= n;
      ret++;
    }
  }
}
