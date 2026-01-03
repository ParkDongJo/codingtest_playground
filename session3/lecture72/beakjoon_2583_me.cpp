#include <bits/stdc++.h>
using namespace std;

const int max_size = 104;

int arr[max_size][max_size];
int visited[max_size][max_size];
vector<pair<pair<int, int>, pair<int, int>>> p;

int n, m, k;
int y1, x1, y2, x2;

void dfs(int y, int x)
{
}

int main()
{
  // 입력을 받고
  cin >> n >> m >> k;

  for (int i = 0; i < k; i++)
  {
    cin >> x1 >> y1 >> x2 >> y2;
    p.push_back({{x1, y1}, {x2, y2}});
  }

  // 자료구조를 만들고
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      arr[j][i] = 0;
    }
  }

  // 직사각형 그리기

  // 빈공간 갯수 세기
}
