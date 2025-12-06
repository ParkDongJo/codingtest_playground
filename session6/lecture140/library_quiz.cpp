#include <bits/stdc++.h>
using namespace std;

int from, to, n, idx = 0, ret = 1;

int main()
{
  cin.tie(NULL);
  cin >> n;

  vector<pair<int, int>> v;

  for (int i = 0; i < n; i++)
  {
    cin >> from >> to;
    v.push_back({to, from});
  }

  // start 를 기준으로 정렬하기 때문에, 여기서는 to 데이터를 기준으로 정렬함
  sort(v.begin(), v.end());
  from = v[0].second;
  to = v[0].first;

  for (int i = 0; i < n; i++)
  {
    // 이전 종료시간보다 시작시간이 빠르면 패스
    if (v[i].second < to)
    {
      continue;
    }
    from = v[i].second;
    to = v[i].first;
    // 이전 종료시간보다 시작시간이 늦으면 카운트 증가
    ret++;
  }

  cout << ret << "\n";

  return 0;
}