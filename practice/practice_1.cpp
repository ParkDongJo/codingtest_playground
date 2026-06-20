
/*
1번 문제
번호를 돌려서 여는 자물쇠가 있습니다. 이 자물쇠는 특이해서, 어떤 번호를 돌리면 바로 다음의 번호도 함께 돌아갑니다.
'돌린다'의 의미는 10진수 숫자에 +1이 되는 것이며, 9 다음 숫자는 0입니다.
예를 들어 '11111'에서 첫번째 번호를 회전시키면, '22111' 처럼 두번째 번호가 함께 돌아갑니다.
'90909'에서 첫번째 번호를 회전시키면, '01909'가 됩니다. 마지막 번호는 혼자 돌아갈 수 없습니다.

자물쇠의 현재 상태를 나타내는 문자열 S와 자물쇠를 여는 비밀번호 문자열 T가 있습니다.
S를 돌려서 T를 만들수 있는 최소의 회전횟수를 구해야합니다.
S를 돌려도 자물쇠를 열 수 없다면(T를 만들 수 없다면) -1을 반환합니다.

예를 들어, '115'는 어떤 번호를 회전시켜도 '116'을 만들 수 없으므로 -1을 반환합니다.
'12345', '12345'는 회전 0회로 달성 가능하므로 0을 반환합니다.

*/

#include <bits/stdc++.h>
using namespace std;

string s, t;
queue<pair<string, int>> pq;
unordered_set<string> visited;

int bfs(string s)
{
  pq.push({s, 0});
  visited.insert(s);

  while (!pq.empty())
  {
    auto [curr, dist] = pq.front();
    pq.pop();

    for (int i = 0; i < curr.size() - 1; i++)
    {
      string next = curr;

      int d1 = curr[i] - '0';
      int d2 = curr[i + 1] - '0';

      next[i] = char('0' + (d1 + 1) % 10);
      next[i + 1] = char('0' + (d2 + 1) % 10);

      if (visited.count(next))
        continue;
      if (next == t)
        return dist + 1;
      visited.insert(next);
      pq.push({next, dist + 1});
    }
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> t;

  if (s == t)
  {
    cout << 0 << "\n";
    return 0;
  }

  int result = bfs(s);
  cout << result << "\n";

  return 0;
}