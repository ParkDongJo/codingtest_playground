#include <bits/stdc++.h>
using namespace std;

int n;
double temp;
priority_queue<double> pq;
vector<double> v;

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &temp);
    if (pq.size() == 5)
    {
      pq.push(temp);
      pq.pop();
    }
    else
      pq.push(temp);
  }
  while (pq.size())
  {
    // 우선순위에 있는 값을 벡터에 추가
    // push back 은 벡터의 맨 뒤에 추가하는 것
    v.push_back(pq.top());
    pq.pop();
  }
  // 벡터를 역순으로 정렬
  reverse(v.begin(), v.end());
  // 벡터를 출력
  for (double i : v)
    printf("%.2lf\n", i);
  return 0;
}