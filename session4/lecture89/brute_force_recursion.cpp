#include <bits/stdc++.h>
using namespace std;

int n, cnt, temp;
vector<int> v;

// 소수를 판별하는 함수
int check(int sum)
{
  if (n <= 1)
    return 0;
  if (n == 2)
    return 1;
  // 짝수는 소수가 아니다
  if (n % 2 == 0)
    return 0;
  for (int i = 2; i * i <= n; i++)
  {
    // 모듈러 연산으로 해서 나머지가 0이면 소수가 아니다
    if (n % i == 0)
      return 0;
  }
  // 지금까지의 조건을 다 만족하면 소수다
  return 1;
}

int go(int idx, int sum)
{
  if (idx == n)
  {
    return check(sum);
  }
  return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    v.push_back(temp);
  }

  cout << go(0, 0) << "\n";

  return 0;
}