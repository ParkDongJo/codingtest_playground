const input = require('fs').readFileSync(0, 'utf8').trim().split('\n');

const [R, C] = input[0].split(' ').map(Number);
const a = input.slice(1, 1 + R).map((line) => line.trim());

const visited = new Array(26).fill(0);
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
let ret = 0;

// y, x : 현재 위치
// cnt  : 지금까지 지나온 칸 수
function go(y, x, cnt) {
  ret = Math.max(ret, cnt);
  for (let i = 0; i < 4; i++) {
    const ny = y + dy[i];
    const nx = x + dx[i];
    
    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    const next = a[ny].charCodeAt(nx) - 65; // 'A'
    if (visited[next] === 0) {
      visited[next] = 1;
      go(ny, nx, cnt + 1);
      visited[next] = 0;
    }
  }
}

visited[a[0].charCodeAt(0) - 65] = 1;
go(0, 0, 1);
console.log(ret);
