#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ret, temp1, temp;
int main()
{

  // 빠른 입출력
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  vector<pair<ll, ll>> items(n);
  vector<ll> bags(k);

  for (int i = 0; i < n; i++)
  {
    cin >> items[i].first >> items[i].second;
  }
  for (int i = 0; i < k; i++)
  {
    cin >> bags[i];
  }
  sort(items.begin(), items.end());
  sort(bags.begin(), bags.end());

  priority_queue<ll> pq;

  int itemIndex = 0;
  // 가방 수만큼 반복
  for (int i = 0; i < k; i++)
  {
    // 골동품 수만큼 반복
    while (itemIndex < n && items[itemIndex].first <= bags[i])
    {
      // 우선순위 큐에 골동품 가치 추가
      pq.push(items[itemIndex].second);
      // 골동품 인덱스 증가
      itemIndex++;
    }
    // 우선순위 큐에 값이 있으면 가치 증가
    if (pq.size())
    {
      ret += pq.top();
      pq.pop();
    }
  }
  cout << ret << "\n";
  return 0;
}