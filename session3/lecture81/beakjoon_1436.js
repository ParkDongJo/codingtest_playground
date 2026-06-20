const n = Number(require('fs').readFileSync('/dev/stdin').toString().trim());

let count = n;
let i = 666;
for (;; i++) {
    if (String(i).includes("666")) count--;
    if (count === 0) break;
}
console.log(i);
