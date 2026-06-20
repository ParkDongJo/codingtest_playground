const input = require('fs').readFileSync(0, 'utf8').split('\n');

const [R, C] = input[0].split(' ').map(Number);
const dy = [0, 1, 0, -1];
const dx = [1, 0, -1, 0];

// 그리드를 평탄화: idx = y * C + x
const a = new Uint8Array(R * C);          // 칸 상태 ('.', 'X', 'L')
const visited = new Uint8Array(R * C);    // 물 BFS 방문
const visitedSwan = new Uint8Array(R * C); // 백조 BFS 방문

const DOT = 46; // '.'
const X = 88;   // 'X'
const L = 76;   // 'L'

// 큐: 좌표 idx만 저장 (head 포인터로 shift 비용 제거)
let waterQ = [];
let waterTempQ = [];
let swanQ = [];
let swanTempQ = [];

let swanIdx = -1;

for (let i = 0; i < R; i++) {
  const row = input[i + 1];
  for (let j = 0; j < C; j++) {
    const c = row.charCodeAt(j);
    const idx = i * C + j;
    a[idx] = c;
    if (c === L) swanIdx = idx;
    if (c === DOT || c === L) {
      visited[idx] = 1;
      waterQ.push(idx);
    }
  }
}

function waterMelting() {
  let head = 0;
  while (head < waterQ.length) {
    const cur = waterQ[head++];
    const y = (cur / C) | 0;
    const x = cur - y * C;
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      const nidx = ny * C + nx;
      if (visited[nidx]) continue;
      if (a[nidx] === X) {
        visited[nidx] = 1;
        waterTempQ.push(nidx);
        a[nidx] = DOT;
      }
    }
  }
}

function moveSwan() {
  let head = 0;
  while (head < swanQ.length) {
    const cur = swanQ[head++];
    const y = (cur / C) | 0;
    const x = cur - y * C;
    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      const nidx = ny * C + nx;
      if (visitedSwan[nidx]) continue;
      visitedSwan[nidx] = 1;
      if (a[nidx] === DOT) swanQ.push(nidx);
      else if (a[nidx] === X) swanTempQ.push(nidx);
      else if (a[nidx] === L) return true;
    }
  }
  return false;
}

swanQ.push(swanIdx);
visitedSwan[swanIdx] = 1;

let day = 0;
while (true) {
  if (moveSwan()) break;
  waterMelting();
  waterQ = waterTempQ;
  swanQ = swanTempQ;
  waterTempQ = [];
  swanTempQ = [];
  day++;
}

console.log(day);
