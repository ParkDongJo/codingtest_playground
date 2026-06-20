const dp = Array(1004).fill(-1);

// 탑다운은 재귀적인으로 표현하는 경우가 많음
// 단점은 오버헤드가 크다. (= 더 많은 시간이 걸린다)
// 장점은 꼭 필요한 DP만 만들고, 직관적이다.

function fibo(n) {
  // 기저 사례
  if (n <= 1) return n;

  // 메모이제이션
  if (dp[n] !== -1) return dp[n];

  // 로직
  dp[n] = fibo(n - 1) + fibo(n - 2);
  return dp[n];
}

const n = 10;
const ret = fibo(n);
console.log(ret);
