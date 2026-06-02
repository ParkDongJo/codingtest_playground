function fact(n) {
    if (n === 0) return 1;
    return n * fact(n - 1);
}

// 재귀는 반복문으로 호출 가능
function factByFor(n) {
    let res = 1;
    for (let i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

function fibo(n) {
    if (n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

const n = 5;

console.log(fact(n));
console.log(fibo(n));
