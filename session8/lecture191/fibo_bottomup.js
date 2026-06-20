// 바텀업은 반복문으로 표현하는 경우가 많음
// 단점은 모든 DP를 만든다.
// 장점은 오버헤드가 발생하지 않는다. (그래서 속도가 더 빠르다)

// 초기화
const dp = Array(1004).fill(-1);
const n = 10;
dp[0] = 0;
dp[1] = 1;

// 로직
// i 는 2부터
for (let i = 2; i <= n; i++) {
  dp[i] = dp[i - 1] + dp[i - 2];
}

console.log(dp[n]);
