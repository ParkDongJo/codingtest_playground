#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
  cin >> n;

  // vector<pair<int,int>> a 에 n 숫자를 지정해서 크기를 정할 수 있다.
  vector<pair<int, int>> a(n);

  for (int i = 0; i < n; i++)
  {
    // vector 에 바로 입력할 수도 있다.
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(), a.end());

  int realTime = a[0].first + a[0].second;

  for (int i = 1; i < a.size(); i++)
  {
    // 계속해서 max 를 갱신해 간다.
    // 이렇게 하면 둘을 비교할 필요 없이 아래와 같이 하면 된다.
    realTime = max(realTime, a[i].first);
    realTime += a[i].second;
  }

  cout << realTime << "\n";
  return 0;
}
