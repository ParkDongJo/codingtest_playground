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

const v = [];
let ret = 0;
// Max-heap
const pq = new Heap((a, b) => b - a);

const n = Number(readLine());
for (let i = 0; i < n; i++) {
  const [deadline, ramen] = readLine().split(' ').map(Number);
  v.push([deadline, ramen]);
}

// 데드라인으로 정렬을 해야, 그 중에서 라면 최대를 뽑을 수 있으니까
v.sort((a, b) => a[0] - b[0] || a[1] - b[1]);

let current_deadline = v[0][0];
for (let i = 0; i < n; i++) {
  // 이렇게 하면... 6일 데드라인은 1개인데, 이게 연산에 포함이 안된다
  // ... 추가 처리가 필요하다
  if (v[i][0] === current_deadline) {
    pq.push(v[i][1]);
  } else {
    if (pq.size() > 0) {
      ret += pq.top();
      console.log(pq.top() + "====");
      pq = new Heap((a, b) => b - a);
    }
    current_deadline = v[i][0];
  }
}
console.log(ret);
