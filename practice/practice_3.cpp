
/*
3번 문제
어떤 문자열이 주어졌을 때, 예를 들어 'abcdef'에 대해 'a', 'ab', 'abc', 'abcd', 'abcde' 와 같이 전체 문자열이 아니면서 앞에서부터 잘라낸 부분 문자열을 prefix라 합니다. 반대로 'f', 'ef', 'def', 'cdef', 'bcdef'와 같이 전체 문자열이 아니면서 뒤에서부터 잘라낸 부분 문자열을 suffix라 합니다.

어떤 문자열이 주어졌을 때, prefix이면서 suffix인 문자열 중 가장 길이가 긴 문자열의 길이를 반환합니다.

예를 들어, 'ababab'의 경우, prefix는 'a', 'ab', 'aba', 'abab', 'ababa'입니다. suffix는 'b', 'ab', 'bab', 'abab', 'babab'입니다. 'abab'는 prefix이면서 동시에 suffix인 가장 긴 문자열이므로 4를 반환합니다.

*/

#include <bits/stdc++.h>
using namespace std;

string s;
int n, ret = 0;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s; // 예: "ababab"

  n = s.size();

  for (int i = n - 1; i >= 1; --i)
  {
    string prefix = s.substr(0, i);
    string suffix = s.substr(n - i, i);
    if (prefix == suffix)
    {
      ret = i;
      break;
    }
  }

  cout << ret << "\n";

  return 0;
}