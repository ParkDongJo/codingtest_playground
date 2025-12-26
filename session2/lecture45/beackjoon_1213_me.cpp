#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
  cin >> s;
  sort(s.begin(), s.end());
  string head = "";
  string tail = "";
  char mid;

  int count = 0;
  for (int i = 0; i < s.size(); i++)
  {

    if (i / 2 == 0)
    {
      head += s[i];
    }
    else
    {
      if (head[head.size() - 1] == s[i])
      {
        tail + s[i];
      }
      // 여기서 꼬임
      else
      {
        count++;
        if (count > 1)
        {
          cout << "I'm Sorry Hansoo" << "\n";
          return 0;
        }
        else
        {
          mid = s[i];
        }
      }
    }
  }
  cout << head + mid + tail << "\n";
  return 0;
}

// 테스트 자동화
