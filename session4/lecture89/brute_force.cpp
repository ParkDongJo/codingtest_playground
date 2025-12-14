#include <bits/stdc++.h>
using namespace std;

int n, cnt;

// 1e7 = 백만
const int INF = 1e7;

int main()
{
  cin >> n;
  for (int i = 0; i < INF; i++)
  {
    string a = to_string(i);
    // string::npos = 문자열을 찾을 수 없는 경우
    if (a.find("240") != string::npos)
    {
      cnt++;
      if (n == cnt)
      {
        cout << a << "\n";
        break;
      }
    }
  }
  return 0;
}
