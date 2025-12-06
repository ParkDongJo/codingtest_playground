#include <bits/stdc++.h>
using namespace std;
int n, result, x;

int main()
{
  cin >> n;
  // n개 만큼 벡터를 만들고, 입력값을 넣는다.
  vector<int> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  // x 값을 입력받는다.
  cin >> x;

  // 정렬을 시킨다.
  sort(a.begin(), a.end());

  // 왼쪽 포인터와 오른쪽 포인터를 초기화한다.
  int left = 0, right = n - 1;
  while (left < right)
  {
    // 두 수를 더했을 때, X와 같으면, 오른쪽 포인터를 왼쪽으로 (더 작은수가 되도록)
    // 그리고 결과카운팅을 한개씩 올린다.
    if (a[left] + a[right] == x)
    {
      right--;
      result++;
    }
    // 두 수를 더했을 때, X 보다 작으면, 왼쪽 포인터를 오른족으로 (더 큰수가 되도록)
    else if (a[left] + a[right] < x)
    {
      left++;
    }
    // 두 수를 더했을 때, X 보다 크면, 오른쪽 포인터를 왼쪽으로 (더 작은수가 되도록)
    else if (a[left] + a[right] > x)
    {
      right--;
    }
  }
  cout << result << "\n";
}