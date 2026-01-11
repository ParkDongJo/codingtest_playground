#include <bits/stdc++.h>
using namespace std;

// 이런식으로 타입을 재활용할 수가 있는듯
typedef long long ll;
// 범위를 보고 ll 로 선언을 했다.
ll n, k, ret, temp1, temp;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  // 보석 목록 셋팅
  vector<pair<ll, ll>> v(n);
  // 가방 목록 셋팅
  vector<ll> vv(k);

  // 보석 셋팅
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
  }

  // 가방 셋팅
  for (int i = 0; i < k; i++)
    cin >> vv[i];

  // 두 목록 정렬
  sort(v.begin(), v.end());
  sort(vv.begin(), vv.end());

  priority_queue<ll> pq;

  int j = 0;
  // 가방 개수 만큼 돈다
  for (int i = 0; i < k; i++)
  {
    // 보석을 하나씩 탐색
    // j가 보석의 수보다 적고
    // 보석의 무게가 가방의 무게보다 적을때
    while (j < n && v[j].first <= vv[i])
      pq.push(v[j++].second);

    // 큐에 들어가 있는 것을 중 가장 큰것을 결과값에 더한다.
    if (pq.size())
    {
      ret += pq.top();
      pq.pop();
    }
  }
  cout << ret << "\n";
  return 0;
}