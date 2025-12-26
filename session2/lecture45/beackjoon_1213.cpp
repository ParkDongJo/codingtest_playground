#include <bits/stdc++.h>
using namespace std;

string s;

int cnt[200], flag;
char mid;
string ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  // 글자를 카운팅 한다
  for (char c : s)
    cnt[c]++;

  // 글자를 역순으로 확인한다
  for (int i = 'Z'; i >= 'A'; i--)
  {
    // 글자가 홀수인 경우
    if (cnt[i] & 1)
    {
      // 중앙 글자를 설정한다
      mid = char(i);
      // 중앙 글자를 카운팅 한다
      flag++;
      // 글자를 카운팅 한다
      cnt[i]--;
    }
    // 중앙 글자가 2개 이상인 경우 종료
    if (flag == 2)
      break;

    // 글자를 2개씩 추가한다
    for (int j = 0; j < cnt[i]; j += 2)
    {
      // 글자를 앞에서부터 추가한다
      ret = char(i) + ret;
      // 글자를 뒤에서부터 추가한다
      ret += char(i);
    }
  }
  // 중앙 글자가 있는 경우 추가한다
  if (mid)
    ret.insert(ret.begin() + ret.size() / 2, mid);
  // 중앙 글자가 2개 이상인 경우 종료
  if (flag == 2)
    cout << "I'm Sorry Hansoo" << "\n";
  // 중앙 글자가 없는 경우 출력한다
  else
    cout << ret << "\n";
  return 0;
}