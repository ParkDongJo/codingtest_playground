/*
[문제]
큰돌은 사과를 매우 좋아한다. 그래서 집에 사과나무를 두 그루 심어두고, 그 나무에서 떨어지는
사과를 받아먹곤 한다. 하지만 큰돌은 키가 작아서 사과를 직접 따먹지는 못하고, 사과가 떨어질
때까지 기다린다. 큰돌은 사과가 떨어지는 순간에만 이를 잡을 수 있으며, 사과가 땅에 떨어지면
깨져서 먹을 수 없게 된다.
매 초마다, 두 개의 나무 중 하나에서 사과가 떨어진다. 큰돌이 사과를 잡으려면 사과가 떨어지는
나무 아래에 서 있어야 하며, 큰돌은 빠르게(1초보다 짧은 시간 안에) 다른 나무로 이동할 수 있다.
그러나 큰돌의 체력은 그리 좋지 않아 많이 움직일 수 없다.
큰돌은 S(1≤S≤100)초 동안 사과를 잡을 수 있다. 큰돌은 최대 M(1≤M≤30)번만 이동할 수 있다. 매
초마다 어느 나무에서 사과가 떨어질지에 대한 정보가 주어졌을 때, 큰돌이 받을 수 있는 사과의 최대
개수를 구하는 프로그램을 작성하시오. 큰돌은 처음에는 1번 사과나무 아래에 위치해 있다.


[입력]
첫째 줄에 두 정수 S와 M이 주어진다. 다음 S개의 줄에는 매 초마다 떨어지는 사과의 나무 번호가 1
또는 2로 주어진다.

[출력]
첫째 줄에 큰돌이 받을 수 있는 사과의 최대 개수를 출력한다.
*/

const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

// dp[idx][tree][cnt] 3차원 배열
const dp = Array.from({length: 104}, () => Array.from({length: 2}, () => Array(34).fill(-1)));
const b = Array(104).fill(0);

const [n, m] = readLine().split(' ').map(Number);
for (let i = 0; i < n; i++) {
  b[i] = Number(readLine());
}

function go(idx, tree, cnt) {
  // 1e9 는 10억 아예 마이너스 일때는 말도 안되는 큰 값을 뱉음
  if (cnt < 0) return -1e9;
  if (idx === n) return 0;

  // 이미 계산된 값이면
  if (dp[idx][tree][cnt] !== -1) return dp[idx][tree][cnt];

  // XOR 연산자 활용
  // 1 ^ 1 = 0
  // 1 ^ 0 = 1
  // 0 ^ 1 = 1
  // 0 ^ 0 = 0
  // tree ^ 1 는 현재 나무의 번호를 반전시키는 것이다.
  dp[idx][tree][cnt] = Math.max(
    go(idx + 1, tree ^ 1, cnt - 1), // 다음 나무로 이동하는 경우 (이경우 이동 횟수가 하나 줄어든다.)
    go(idx + 1, tree, cnt)           // 현재 나무에서 사과를 잡는 경우
  ) + (tree === b[idx] - 1 ? 1 : 0);

  return dp[idx][tree][cnt];
}

// 두가지 초기 상태 중 최대값 출력
console.log(Math.max(go(0, 1, m - 1), go(0, 0, m)));
