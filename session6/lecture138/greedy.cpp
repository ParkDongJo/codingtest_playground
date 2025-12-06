#include <bits/stdc++.h>
using namespace std;

int result, totalAmount = 12100;

int main()
{
  vector<pair<int, int>> c = { {10000, 5}, {5000, 5}, {1000, 5}, {1000, 7}, {100, 5};

  // rbegin, rend 는 역순으로 정렬하는 것
  // 벡터는 {first, second} 중 어떤 기준으로 정렬하는가?
  // first 기준으로 정렬하는 것

  // 만약 second 기준으로 정렬하고 싶다면?
  // sort(c.begin(), c.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
  //   return a.second > b.second;
  // });

  sort(c.rbegin(), c.rend());

  // auto &coin : c 는 coin 을 참조하는 것
  // 왜 참조하는가?
  // 참조하면 값을 변경할 수 있기 때문에
  // auto 키워드는 타입을 자동으로 추론하는 것
  // 주로 반복문에서 사용된다.
  for (auto &coin : c)
  {
    while (totalAmount >= coin.first)
    {
      totalAmount -= coin.first;
      coin.second--;
      result++;
    }
  }
  if (totalAmount == 0)
    cout << result << "\n";
  else
    cout << "impossible" << "\n";
  return 0;
}