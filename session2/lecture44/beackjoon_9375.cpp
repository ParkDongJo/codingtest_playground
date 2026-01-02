#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main()
{
  cin >> t;
  map<string, int> mp;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a >> b;
      mp[b]++;
    }

    // 경우의 수 같은 경우는 숫자가 커질 수 있기 때문에, long long 박아두고 문제를 푸는 것이 좋다
    long long ret = 1;
    for (auto c : mp)
    {
      // 종류마다 아무것도 안입은 경우를 +1 해준다.
      ret *= (c.second + 1);
    }
    // 아무것도 안입은 경우
    ret--;
    cout << ret << "\n";
  }
  return 0;
}