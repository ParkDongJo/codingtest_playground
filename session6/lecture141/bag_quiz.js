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

let ret = 0;

const [n, k] = readLine().split(' ').map(Number);

const items = [];
const bags = [];

for (let i = 0; i < n; i++) {
  const [w, v] = readLine().split(' ').map(Number);
  items.push([w, v]);
}
for (let i = 0; i < k; i++) {
  bags.push(Number(readLine()));
}
items.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
bags.sort((a, b) => a - b);

// Max-heap on value
const pq = new Heap((a, b) => b - a);

let itemIndex = 0;
// 가방 수만큼 반복
for (let i = 0; i < k; i++) {
  // 골동품 수만큼 반복
  while (itemIndex < n && items[itemIndex][0] <= bags[i]) {
    // 우선순위 큐에 골동품 가치 추가
    pq.push(items[itemIndex][1]);
    // 골동품 인덱스 증가
    itemIndex++;
  }
  // 우선순위 큐에 값이 있으면 가치 증가
  if (pq.size()) {
    ret += pq.top();
    pq.pop();
  }
}
console.log(ret);
