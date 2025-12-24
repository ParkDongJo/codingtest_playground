// https://www.acmicpc.net/problem/15686

#include <bits/stdc++.h>
using namespace std;
int n, m, a[54][54], result = 987654321;
vector<vector<int>> chickenList;
vector<pair<int, int>> _home, chicken;
void combi(int start, vector<int> v)
{
  if (v.size() == m)
  {
    // 조합을 통한 로직!
    chickenList.push_back(v);
    return;
  }
  for (int i = start + 1; i < chicken.size(); i++)
  {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
  return;
}

// 1단계 무식하게 풀수 있는지 가늠을 해본다!
int main()
{
  cin >> n >> m;

  // 조합의 연산을 쉽게 하기 위해, 2차원 배열로 입력값을 넣어둔다
  // 인덱스를 기반으로 데이터를 다루기 위함
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 1)
        _home.push_back({i, j});
      if (a[i][j] == 2)
        chicken.push_back({i, j});
    }
  }

  vector<int> v;
  combi(-1, v);

  // 조합을 통해 얻은 가공된 데이터 chickenList를 가지고 무식하게 문제를 풀기위한 완전탐색을 진행한다.
  for (vector<int> cList : chickenList)
  {
    int ret = 0;
    for (pair<int, int> home : _home)
    {
      // 일부러 큰값을 준다.
      int _min = 987654321;
      for (int ch : cList)
      {
        int _dist = abs(home.first - chicken[ch].first) + abs(home.second - chicken[ch].second);
        _min = min(_min, _dist);
      }
      ret += _min;
    }
    result = min(result, ret);
  }
  cout << result << "\n";
  return 0;
}