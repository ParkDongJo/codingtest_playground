#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int n;
string s;
char a[101][101];

string quard(int y, int x, int size)
{
  // 칸이 1개이면 그재서야 기저사례가 발동..
  // 분할을 할수 있을때까지 내려가야 생각하기가 쉽다
  if (size == 1)
    // char 로 받은 값을 string 으로 반환하는 것이라고 보면 됨
    return string(1, a[y][x]);

  // 출발점 뽑아놓고
  char b = a[y][x];
  string ret = "";

  // 첫 출발에 대한 y 값을 시작으로 검사
  for (int i = y; i < y + size; i++)
  {
    // 첫 출발에 대한 x 값을 시작으로 검사
    for (int j = x; j < x + size; j++)
    {
      // 첫 출발점과 다른 숫자가 나오는 즉시!
      if (b != a[i][j])
      {
        ret += '(';
        // 1사분면
        ret += quard(y, x, size / 2);
        // 2사분면
        ret += quard(y, x + size / 2, size / 2);
        // 3사분면
        ret += quard(y + size / 2, x, size / 2);
        // 4사분면
        ret += quard(y + size / 2, x + size / 2, size / 2);
        ret += ')';
        // 최종 결과 반환
        return ret;
      }
    }
  }

  // 위의 체크를 모두 통과하고 전혀 해당이 안된다면
  // 전체가 0 또는 1 이라는 것이므로, 값을 반환한다.
  return string(1, a[y][x]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  // 입력값 셋팅
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    // 띄워쓰기 없이 10001 이런식으로 들어오면
    // 배열행태로 들어오나보다
    cin >> s;
    for (int j = 0; j < n; j++)
    {
      a[i][j] = s[j];
    }
  }

  // 재귀 시작
  // 출발점 x, y, size
  cout << quard(0, 0, n) << '\n';
  return 0;
}

/*
  풀이는 심플하지만, 생각을 복잡하게 가져갔다.
  분할 정복을 풀때는, 공통적으로 가져갈 수 있는 것이 무엇이고 그걸 어떻게 반복해서 상위로 올릴까를 생각해내야한다.
  하.. 어렵누
*/