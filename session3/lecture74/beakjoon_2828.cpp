// https://www.acmicpc.net/problem/2828
#include <bits/stdc++.h>
using namespace std;

int n, m, j, ret, r, temp;

int main() {
  cin >> n >> m >> j;

  int l = 1;

  for (int i = 0; i < j; i++) {
    r = l + m - 1;
    cin >> temp;
    if (temp < l && temp <= r) continue;
    else {
      if (temp < l) {
        ret += (l - temp);
        l = temp;
      } else {
        l += (temp - r);
        ret += (temp - r);
      }
    }
  }

  cout << ret << "\n";
  return 0;
}