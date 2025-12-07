#include <bits/stdc++.h>
using namespace std;

/*
8방향에서는 아래와 같다!! 왜 그런지 인접행렬을 바탕으로 생각을 해보자



*/

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
  int y = 0, x = 0;
  for (int i = 0; i < 8; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    cout << ny << " : " << nx << '\n';
  }
  return 0;
}