#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
int deadline, ramen;
priority_queue<int> pq;
int ret = 0;

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> deadline >> ramen;
    v.push_back({deadline, ramen});
  }

  // 데드라인으로 정렬을 해야, 그 중에서 라면 최대를 뽑을 수 있으니까
  sort(v.begin(), v.end());

  int current_deadline = v[0].first;
  for (int i = 0; i < n; i++)
  {
    // 이렇게 하면... 6일 데드라인은 1개인데, 이게 연산에 포함이 안된다
    // ... 추가 처리가 필요하다
    if (v[i].first == current_deadline)
    {
      pq.push(v[i].second);
    }
    else
    {
      if (pq.size() > 0)
      {
        ret += pq.top();
        cout << pq.top() << "====\n";
        pq = priority_queue<int>();
      }
      current_deadline = v[i].first;
    }
  }
  cout << ret << "\n";
  return 0;
}