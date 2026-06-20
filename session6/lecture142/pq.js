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

const n = Number(readLine());
// Max-heap (default priority_queue in C++ is max-heap)
const pq = new Heap((a, b) => b - a);
const v = [];

for (let i = 0; i < n; i++) {
  const temp = parseFloat(readLine());
  if (pq.size() === 5) {
    pq.push(temp);
    pq.pop();
  } else {
    pq.push(temp);
  }
}

while (pq.size()) {
  // 우선순위에 있는 값을 벡터에 추가
  // push back 은 벡터의 맨 뒤에 추가하는 것
  v.push(pq.top());
  pq.pop();
}
// 벡터를 역순으로 정렬
v.reverse();
// 벡터를 출력
for (const i of v)
  console.log(i.toFixed(2));
