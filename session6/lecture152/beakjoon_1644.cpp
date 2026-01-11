#include <bits/stdc++.h>
using namespace std;
bool che[4000001];
int n, a[2000001], p, lo, hi, ret, sum;

int main()
{
  scanf("%d", &n);

  // 에라토스테네스체 를 만드는 과정
  for (int i = 2; i <= n; i++)
  {
    if (che[i])
      continue;
    for (int j = 2 * i; j <= n; j += i)
    {
      che[j] = 1;
    }
  }
  for (int i = 2; i <= n; i++)
  {
    if (!che[i])
      a[p++] = i;
  }

  // 투포인터 과정
  while (1)
  {
    if (sum >= n)
      sum -= a[lo++];

    //  high 와 p(소수의 개수) 가 같다면, 루프를 빠져나온다.
    else if (hi == p)
      break;
    else
      sum += a[hi++];
    if (sum == n)
      ret++;
  }
  printf("%d\n", ret);
}