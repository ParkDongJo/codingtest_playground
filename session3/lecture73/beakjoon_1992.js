const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let n;
let s;
const a = Array.from({ length: 101 }, () => Array(101).fill(''));

function quard(y, x, size) {
  // 칸이 1개이면 그재서야 기저사례가 발동..
  // 분할을 할수 있을때까지 내려가야 생각하기가 쉽다
  if (size === 1)
    // char 로 받은 값을 string 으로 반환하는 것이라고 보면 됨
    return a[y][x];

  // 출발점 뽑아놓고
  const b = a[y][x];
  let ret = "";

  // 첫 출발에 대한 y 값을 시작으로 검사
  for (let i = y; i < y + size; i++) {
    // 첫 출발에 대한 x 값을 시작으로 검사
    for (let j = x; j < x + size; j++) {
      // 첫 출발점과 다른 숫자가 나오는 즉시!
      if (b !== a[i][j]) {
        let ret = '(';
        // 1사분면
        ret += quard(y, x, Math.floor(size / 2));
        // 2사분면
        ret += quard(y, x + Math.floor(size / 2), Math.floor(size / 2));
        // 3사분면
        ret += quard(y + Math.floor(size / 2), x, Math.floor(size / 2));
        // 4사분면
        ret += quard(y + Math.floor(size / 2), x + Math.floor(size / 2), Math.floor(size / 2));
        ret += ')';
        // 최종 결과 반환
        return ret;
      }
    }
  }

  // 위의 체크를 모두 통과하고 전혀 해당이 안된다면
  // 전체가 0 또는 1 이라는 것이므로, 값을 반환한다.
  return a[y][x];
}

// 입력값 셋팅
n = Number(readLine());
for (let i = 0; i < n; i++) {
  // 띄워쓰기 없이 10001 이런식으로 들어오면
  // 배열행태로 들어오나보다
  s = readLine();
  for (let j = 0; j < n; j++) {
    a[i][j] = s[j];
  }
}

// 재귀 시작
// 출발점 x, y, size
console.log(quard(0, 0, n));

/*
  풀이는 심플하지만, 생각을 복잡하게 가져갔다.
  분할 정복을 풀때는, 공통적으로 가져갈 수 있는 것이 무엇이고 그걸 어떻게 반복해서 상위로 올릴까를 생각해내야한다.
  하.. 어렵네
*/
