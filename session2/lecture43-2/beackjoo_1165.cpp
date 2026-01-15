#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;

map<string, int> mp;
map<int, string> mp2;

// 공간의 버퍼를 두기위해 100000 만큼만 넣는게 아니라, 100004 로 약간 버퍼를 두면,
// 나중에 약간의 연산 차이를 놓쳤을때, 헤매지 않을 수 있다.
string a[100004];

int main()
{

  // --------------------
  // 입출력 속도 향상을 위해 사용하는 코드
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // --------------------

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    mp[s] = i + 1;
    mp2[i + 1] = s;

    // 이건 왜?
    a[i + 1] = s;
  }

  for (int i = 0; i < m; i++)
  {
    cin >> s;
    if (atoi(s.c_str()) == 0)
    {
      cout << mp[s] << "\n";
    }
    else
    {
      cout << mp2[atoi(s.c_str()] << "\n"; // 포켓몬 번호
    }
  }

  return 0;
}