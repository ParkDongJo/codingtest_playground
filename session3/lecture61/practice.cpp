#include <bits/stdc++.h>
using namespace std;

// d 는 direction 의 약자
// 방향키라고 생각하자!!
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int main()
{

  int y = 0, x = 0;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    cout << ny << " " << nx << endl;
  }

  return 0;
}