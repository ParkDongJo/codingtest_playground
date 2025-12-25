#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
  while (scanf("%d", &n) != EOF)
  {
    int cnt = 1, ret = 1;
    while (true)
    {
      if (cnt % n == 0)
      {
        printf("%d\n", ret);
        // flag 를 줄 필요 없이 break 를 활용하자!
        // 알고리즘 문제 풀땐.. 이게 더 좋을것 같다!
        break;
      }
      else
      {
        // 이전 계산에 대한 결과를 그대로 사용하면 더 빠르다.
        cnt = (cnt * 10) + 1;
        // 정수 모듈연산의 법칙을 적용하면 더 빠르다.
        // cnt %= n;
        ret++;
      }
    }
  }
  return 0;
}