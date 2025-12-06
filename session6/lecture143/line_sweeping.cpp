#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> line;
line totalLines[1000004];
int n, from, to, front, tail, result;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> from >> to;
    totalLines[i] = line(from, to);
  }
  sort(totalLines, totalLines + n);
  front = totalLines[0].first;
  tail = totalLines[0].second;

  for (int i = 1; i < n; i++)
  {

    // 겹치지 않는 경우 tail, front 를 갱신
    if (result < totalLines[i].first)
    {
      // 길이를 더한다.
      result += (tail - front);

      // 새로운 선의 front, tail 을 설정한다.
      front = totalLines[i].first;
      tail = totalLines[i].second;
    }
    // 겹치는 경우, tail 만 갱신
    else if (totalLines[i].first <= front && totalLines[i].second >= tail)
    {
      tail = totalLines[i].second;
    }
  }
  result += (tail - front);
  cout << result << '\n';
}