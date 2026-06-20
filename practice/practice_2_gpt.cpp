#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  if (!(cin >> N))
    return 0;

  vector<long long> A(N), B(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  for (int i = 0; i < N; ++i)
    cin >> B[i];

  long long totalA = 0, totalB = 0;
  for (int i = 0; i < N; ++i)
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

  long long prefixA = 0, prefixB = 0;
  int answer = 0;

  // K는 1 ~ N-1
  for (int K = 1; K <= N - 1; ++K)
  {
    prefixA += A[K - 1];
    prefixB += B[K - 1];

    // A[0..K-1] 합 == target
    // B[0..K-1] 합 == target
    if (prefixA == target && prefixB == target)
    {
      ++answer;
    }
  }

  cout << answer << '\n';
  return 0;
}
