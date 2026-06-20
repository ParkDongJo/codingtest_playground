#include <bits/stdc++.h>
using namespace std;

string s;
int n, ret = 0;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  n = s.size();

  vector<int> lps(n, 0); // lps[i] = s[0..i]의 가장 긴 border 길이
  int len = 0;           // 현재까지 매칭된 prefix 길이
  int i = 1;             // lps[0]은 항상 0이므로 1부터 시작

  // i 는 1부터 n-1까지 증가
  while (i < n)
  {
    // 현재 비교군 글자 s[i] 와 s[len] 이 일치하면
    if (s[i] == s[len])
    {
      // 한 글자 더 일치
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      // 불일치
      if (len != 0)
      {
        // len 이 0이 아니면, 더 짧은 border로 돌아가서 다시 비교
        len = lps[len - 1];
      }
      else
      {
        // 더 이상 줄일 border가 없으면 0
        lps[i] = 0;
        i++;
      }
    }
  }

  cout << lps[n - 1] << "\n";

  return 0;
}
