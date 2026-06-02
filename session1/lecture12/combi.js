const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
let line = 0;
const readLine = () => input[line++];

const arr = [1, 2, 3, 4, 5];
let k = 5;

// 재귀함수로 구현
// 4개 이상 뽑을때 재귀 활용
function print(v) {
    console.log(v.join(' '));
}

function combi(start, v, n) {
    if (v.length === k) {
        // 기저사례에서 여기에 특정 로직이 들어가야함
        print(v);
        return;
    }
    for (let i = start + 1; i < n; i++) {
        // 인덱스를 넣어둬서, 추후에 로직에서 인덱스를 기반으로 문제를 푸는게 좋다
        v.push(i);
        combi(i, v, n);
        v.pop();
    }
}

const [n, m] = readLine().split(' ').map(Number);
const v = [];
// combi(-1, v, n);

for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
        for (let k = 0; k < j; k++) {
            console.log(i + ' ' + j + ' ' + k);
        }
    }
}
