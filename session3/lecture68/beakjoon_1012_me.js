const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

let tc, result;
const len = 54;

let arr = Array.from({ length: len }, () => Array(len).fill(0));
let visited = Array.from({ length: len }, () => Array(len).fill(0));

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let n, m, k, y, x;

// 큰돌님은 arr, visited 를 모두 고정으로 최대로 잡아줬다.
// 나같은 경우는 m, n을 받고 곧바로 arr, visited 를 설정해주다 보니 같이 넘겨야했는데
// 알고리즘을 풀때는.. 그냥!! 제약사항이 없다면 미리 잡아두는것이 로직을 더 간단하게 만드는것 같다
function dfs(y, x) {
  visited[y][x] = 1;

  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
      continue;
    }
    if (arr[y][x] === 0) {
      continue;
    }
    if (visited[y][x] === 1) {
      continue;
    }
    dfs(ny, nx);
  }
  return;
}

// 이게 뭐하는 역할일까?
// 성능 최적화를 위해
// cin.tie(NULL)로 이 연결을 끊어서 불필요한 flush를 방지합니다
/*
  놓친 부분이 있다!! tc 만큼 이 로직이 반복해서 돌건데, 그럴려면 1개의 tc가 끝나면 그 다음 tc 를 위해서
  데이터 셋에 대한 초기화가 필요하다.
  초기화를 해주는 코드를 넣어줘야한다
*/
tc = Number(readLine());
const parts = readLine().split(' ').map(Number);
n = parts[0]; m = parts[1]; k = parts[2];

arr = Array.from({ length: n }, () => Array(m).fill(0));
visited = Array.from({ length: n }, () => Array(m).fill(0));

for (let i = 0; i < k; i++) {
  const [tx, ty] = readLine().split(' ').map(Number);
  arr[ty][tx] = 1;
}

result = 0;
for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (arr[i][j] === 1 && visited[i][j] === 0) {
      result++;
      console.log('test');
      dfs(i, j);
    }
  }
}

console.log(result + "-정답");
