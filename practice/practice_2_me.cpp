
/*
2번 문제
운동장 위에 두 줄로 주머니가 놓여있습니다. 각 줄에는 같은 개수의 주머니가 놓여있습니다.
각 주머니에는 금화가 들어있습니다. 각 줄에 들어있는 주머니의 개수 N이라고 할 때, 하나의 선을 그어 그 기준(K)으로 주머니를 나눌 수 있습니다.

위 상태를 배열로 나타낼 수 있습니다.
예를 들어 [1,2,3,4,10]는 각각 금화가 1개, 2개, 3개, 4개, 10개 들어있는 주머니 5개가 놓인 줄을 나타냅니다.
[3,0,7,0,10]는 각각 금화가 3개, 0개, 7개, 0개, 10개 들어있는 주머니 5개가 놓인 줄을 나타냅니다.

이때, 첫번째 주머니 뒤에 선을 그으면(K = 1)이면 다음의 4개의 작은 배열로 나뉘게 됩니다.

[1], [2,3,4,10],
[3], [0,7,0,10]

각 배열의 내부합은 1, 19, 3, 17로 모두 다르므로 '공평'하지 않다고 합니다.

만약 K = 4 인 경우,

[1,2,3,4], [10],
[3,0,7,0], [10]

모든 배열의 내부합이 10으로 같으므로 '공평'합니다.

길이가 같은 두 배열이 주어졌을 때, '공평'한 분할 방법의 개수를 반환합니다. 위의 예시의 경우에는 K = 4인 경우 하나만 성립하므로, 1을 반환합니다.

*/

#include <bits/stdc++.h>
using namespace std;

int n;
long long totalA, totalB;
long long prefixA = 0, prefixB = 0;
int ret;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // --- 입력
  cin >> n;

  vector<long long> A(n), B(n);

  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = 0; i < n; ++i)
    cin >> B[i];

  // --- 입력

  long long totalA = 0, totalB = 0;
  for (int i = 0; i < n; ++i)
  {
    totalA += A[i];
    totalB += B[i];
  }

  // 총합이 다르면 애초에 네 구간의 합이 모두 같을 수 없음
  if (totalA != totalB)
  {
    cout << 0 << '\n';
    return 0;
  }

  // 절반으로 못 나누면 (홀수면) 네 구간 합이 같을 수 없음
  if (totalA % 2 != 0)
  {
    cout << 0 << '\n';
    return 0;
  }

  long long target = totalA / 2; // 각 줄에서 왼쪽 구간 합이 되어야 하는 값

  // K는 1 ~ N-1
  for (int i = 1; i <= n - 1; ++i)
  {
    prefixA += A[i - 1];
    prefixB += B[i - 1];

    // A[0..K-1] 합 == target
    // B[0..K-1] 합 == target
    if (prefixA == target && prefixB == target)
    {
      ++ret;
    }
  }

  cout << ret << '\n';
  return 0;
}
