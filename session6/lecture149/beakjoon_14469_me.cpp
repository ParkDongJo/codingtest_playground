#include <bits/stdc++.h>
using namespace std;

int n, from, dist;
vector<pair<int, int>> line;
int start, to;

int main()
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> from >> dist;
    line.push_back({from, dist});
  }

  sort(line.begin(), line.end());

  int to;
  for (int i = 0; i < n; i++)
  {
    to = line[i].first + line[i].second;

    if (to > line[i + 1].first)
    {
      line[i + 1].first = to;
    }
  }

  cout << line[n - 1].first + line[n - 1].second;

  return 0;
}