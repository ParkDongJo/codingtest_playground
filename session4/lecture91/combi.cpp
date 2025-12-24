#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v_list;

void combi(int start, vector<int> v)
{
  if (v.size() == m)
  {
    v_list.push_back(v);
    return;
  }
  for (int i = start + 1; i < n; i++)
  {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
  return;
}

int main()
{
  cin >> n >> m;
  vector<int> v;
  combi(-1, v);
  return 0;
}