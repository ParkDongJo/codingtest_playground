#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, temp, psum[100001], ret = -10000004;
int a[100000];

// 연속의 온도의 합이 "최대" 되느니 값
//  = 구간합 prefix sum, psum[i] = psum[i - 1] + a[i]

// 최대값
// = 최솟갑 ~ 최대값
// = max(ret, value)
// 최소값
// = 최대값 ~ 최소값
// = min(ret, value)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }
  for (int i = k; i <= n; i++)
  {
    ret = max(ret, psum[i] - psum[i - k]);
  }
  cout << ret << "\n";
  return 0;
}