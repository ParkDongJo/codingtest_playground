#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n, m, k = 5;
vector<int> arr = {1, 2, 3, 4, 5};

// 재귀함수로 구현
// 4개 이상 뽑을때 재귀 활용
void print(vector<int> v)
{
  for (int i : v)
  {
    cout << i << " ";
  }
  cout << "\n";
}

void combi(int start, vector<int> v)
{
  if (v.size() == k)
  {
    // 기저사례에서 여기에 특정 로직이 들어가야함
    print(v);
    return;
  }
  for (int i = start + 1; i < n; i++)
  {
    v.push_back(i);
    combi(i, v);
    v.pop_back();
  }
}

int main()
{
  cin >> n >> m;
  vector<int> v;
  // combi(-1, v);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      for (int k = 0; k < j; k++)
      {
        cout << i << " " << j << " " << k << "\n";
      }
    }
  }

  return 0;
}