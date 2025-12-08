#include <bits/stdc++.h>
using namespace std;

int n, ret;
int front, tail;
vector<pair<int, int>> v;
vector<pair<int, int>> r;

int main()
{
  // 이건 왜?
  cin.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> front >> tail;
    v.push_back({front, tail});
  }

  sort(v.begin(), v.end());

  int curr_end = v[0].second;
  for (int i = 1; i < n; i++)
  {
    if (v[i].first < curr_end)
    {
      continue;
    }
    curr_end = v[i].second;
    ret++;
  }

  cout << ret << "\n";

  return 0;
}