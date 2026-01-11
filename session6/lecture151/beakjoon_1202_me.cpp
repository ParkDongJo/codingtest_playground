#include <bits/stdc++.h>
using namespace std;

int n, k, c, ret;

vector<pair<int, int>> temps;
vector<pair<int, int>> bags;

int main()
{
  cin.tie(NULL);

  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    int m, v;
    cin >> m >> v;
    temps.push_back({m, v});
  }

  cin >> c;

  for (pair<int, int> t : temps)
  {
    if (t.first <= c)
    {
      bags.push_back(t);
    }
  }

  sort(
      bags.begin(), bags.end(),
      [](const auto &a, const auto &b)
      {
        return a.second < b.second;
      });

  for (int i = 0; i < c; i++)
  {
    ret += bags[i].second;
  }
  cout << ret;
}