#include <bits/stdc++.h>
using namespace std;

int n, cnt, temp;
vector<int> v;
int ret;
const int mod = 11;

void go(int idx, int sum)
{
  if (idx == n)
  {
    // 보통 완전탐색에서 재귀를 쓸땐
    // 기저사례에서 원하는 로직을 구현한다
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

  // 만약 문제에서 최대값을 구하라고 했으면 -> 최소값부터 시작해야한다
  // 반대로 최소값을 구하라고 했으면 -> 최대값부터 시작해야한다
  // 더 중요한건 이 초기값은 답의 범위가 될 수 없는 가장 최소값(최대값)이어야 한다.
  go(0, 0);

  cout << ret << "\n";
  cout << cnt << "\n";

  return 0;
}