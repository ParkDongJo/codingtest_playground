#include <bits/stdc++.h>
using namespace std;

string line;
string bomb;
stack<char> st;

// 근데 이게 그리디랑 뭔 관계지?
int main()
{
  cin >> line >> bomb;

  while (true)
  {
    // 아래 코드를 해석해보자
    // find() 함수가 bomb 을 찾지 못하면 string::npos 를 반환한다.
    // 즉 아래 조건문은 bomb 를 line 에서 찾았다는 의미이다.
    if (line.find(bomb) != string::npos)
    {
      // find() 함수는 찾으면 index 를 반환한다.
      // 즉 아래 코드는 bomb 의 크기만큼 line 에서 제거한다.
      line.erase(line.find(bomb), bomb.size());
    }
    else
    {
      // 못찾으면 반복문을 중단한다.
      break;
    }
  }
  if (line.empty())
  {
    cout << "FRULA" << endl;
  }
  cout << line << endl;
  return 0;
}