const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

/*
  내가 stack 을 생각을 했었는데, 유사한 접근이긴 했지만, 큰돌님은 그냥 string 인채에서
  2글자일때마다 끝의 2글자만 비교를 해서 제거해주는 식으로 문제를 풀었다.

  근데 생각을 해보면 stack 으로 한다고 했을때, 마지막 n글자는 갱신을 해서 폭발 문자열과 계속 비교를 하는 로직을 넣는게 더 비교하기 쉬울것 같다
*/

const S = readLine();
const T = readLine();
let ret = '';

for (const a of S) {
  ret += a;
  // 여기서 c++ 은 문자열 비교에 대해서 == 으로 바로 비교해도 된다.
  if (ret.length >= T.length && ret.substring(ret.length - T.length) === T) {
    ret = ret.substring(0, ret.length - T.length);
  }
}
if (!ret.length)
  console.log("FRULA");
else
  console.log(ret);
