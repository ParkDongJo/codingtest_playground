#include <bits/stdc++.h>
using namespace std;

// S를 T로 만드는 최소 회전 횟수를 반환, 불가능하면 -1
int minRotations(string S, string T)
{
  if (S.size() != T.size())
    return -1; // 방어 코드
  if (S == T)
    return 0;

  int n = S.size();

  queue<pair<string, int>> q;    // {상태 문자열, 회전 횟수}
  unordered_set<string> visited; // 방문 체크

  q.push({S, 0});
  visited.insert(S);

  while (!q.empty())
  {
    auto [cur, dist] = q.front();
    q.pop();

    // 현재 상태에서 모든 가능한 회전 위치 시도
    for (int i = 0; i < n - 1; ++i)
    {
      string next = cur;

      // i, i+1 두 자리 +1 (mod 10)
      int d1 = next[i] - '0';
      int d2 = next[i + 1] - '0';
      d1 = (d1 + 1) % 10;
      d2 = (d2 + 1) % 10;
      next[i] = char('0' + d1);
      next[i + 1] = char('0' + d2);

      if (visited.count(next))
        continue;

      if (next == T)
        return dist + 1;

      visited.insert(next);
      q.push({next, dist + 1});
    }
  }

  // 큐를 다 소모할 동안 T를 만들지 못한 경우
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string S, T;
  cin >> S >> T;

  int ans = minRotations(S, T);
  cout << ans << "\n";

  return 0;
}
