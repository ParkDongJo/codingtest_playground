#include <bits/stdc++.h>
using namespace std;

int n, ret, sum = 0;
vector<int> v;

// 소수를 판별하는 함수
bool isPrime(int n)
{
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main()
{
  cin >> n;

  for (int i = 2; i <= n; i++)
  {
    if (isPrime(i))
      v.push_back(i);
  }

  int left = 0, right = 0;

  while (left < v.size() && right < v.size())
  {
    if (sum < n)
      sum += v[right++];
    else if (sum > n)
      sum -= v[left++];
    else if (sum == n)
    {
      ret++;
      sum += v[right++];
    }
  }

  cout << ret << "\n";

  return 0;
}