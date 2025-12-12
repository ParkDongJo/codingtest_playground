#include <bits/stdc++.h>
using namespace std;

int dp[1004];

// 탑다운은 재귀적인으로 표현하는 경우가 많음
// 단점은 오버헤드가 크다. (= 더 많은 시간이 걸린다)
// 장점은 꼭 필요한 DP만 만들고, 직관적이다.

int fibo(int n)
{
  // 기저 사례
  if (n <= 1)
    return n;

  // 메모이제이션
  int &ret = dp[n];
  if (ret != -1)
    return ret;

  // 로직
  return ret = fibo(n - 1) + fibo(n - 2);
}
int main()
{
  int n = 10;

  // 초기화
  memset(dp, -1, sizeof(dp));

  int ret = fibo(n);
  cout << ret << '\n';
}