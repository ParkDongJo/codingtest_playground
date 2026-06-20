const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

class Heap {
  constructor(cmp = (a, b) => a - b) { this.data = []; this.cmp = cmp; }
  push(v) { this.data.push(v); this._up(this.data.length - 1); }
  pop() { const top = this.data[0]; const last = this.data.pop(); if (this.data.length) { this.data[0] = last; this._down(0); } return top; }
  top() { return this.data[0]; }
  size() { return this.data.length; }
  _up(i) { while (i > 0) { const p = (i - 1) >> 1; if (this.cmp(this.data[i], this.data[p]) < 0) { [this.data[i], this.data[p]] = [this.data[p], this.data[i]]; i = p; } else break; } }
  _down(i) { const n = this.data.length; while (true) { let s = i, l = 2*i+1, r = 2*i+2; if (l < n && this.cmp(this.data[l], this.data[s]) < 0) s = l; if (r < n && this.cmp(this.data[r], this.data[s]) < 0) s = r; if (s === i) break; [this.data[i], this.data[s]] = [this.data[s], this.data[i]]; i = s; } }
}

// 이런식으로 타입을 재활용할 수가 있는듯
// 범위를 보고 ll 로 선언을 했다.
let ret = 0;

const [n, k] = readLine().split(' ').map(Number);

// 보석 목록 셋팅
const v = [];
// 가방 목록 셋팅
const vv = [];

// 보석 셋팅
for (let i = 0; i < n; i++) {
  const [w, val] = readLine().split(' ').map(Number);
  v.push([w, val]);
}

// 가방 셋팅
for (let i = 0; i < k; i++)
  vv.push(Number(readLine()));

// 두 목록 정렬
v.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
vv.sort((a, b) => a - b);

// Max-heap
const pq = new Heap((a, b) => b - a);

let j = 0;
// 가방 개수 만큼 돈다
for (let i = 0; i < k; i++) {
  // 보석을 하나씩 탐색
  // j가 보석의 수보다 적고
  // 보석의 무게가 가방의 무게보다 적을때
  while (j < n && v[j][0] <= vv[i])
    pq.push(v[j++][1]);

  // 큐에 들어가 있는 것을 중 가장 큰것을 결과값에 더한다.
  if (pq.size()) {
    ret += pq.top();
    pq.pop();
  }
}
console.log(ret);
