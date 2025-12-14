#include <bits/stdc++.h>
using namespace std;

int n, cnt, temp;
vector<int> v;
int ret;
const int mod = 11;

void go(int idx, int sum)
{
  // 벡트레킹 가지치기!!!
  if (ret == mod - 1)
    return;
  if (idx == n)
  {
    ret = max(ret, sum % mod);
    cnt++;
    return;
  }
  go(idx + 1, sum + v[idx]);
  go(idx + 1, sum);
}

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    v.push_back(temp);
  }

  go(0, 0);

  cout << ret << "\n";
  cout << cnt << "\n";

  return 0;
}