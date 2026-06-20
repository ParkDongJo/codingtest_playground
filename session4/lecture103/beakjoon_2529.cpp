include <bits/stdc++.h>
using namespace std;
int n;
char a[10];
bool check[10];
vector<string> ret;


bool good(char a, char b, char op) {
  if (op == '<') return a < b;
  else return a > b;
}

void go(int idx, string num) {
  if (idx == n + 1) {
    ret.push_back(num);
    return;
  }
  for (int i = 0; i < 10; i++) {
    // 이미 사용한 숫자라면 건너뛴다.
    if (check[i]) continue;
    // idx가 0이라면 어떤 숫자든 올 수 있다.
    // idx가 0이 아니라면, num의 마지막 숫자와 i 사이에 관계가 성립하는지 확인한다.
    // i + '0' 은 i를 문자로 바꾼 것이다. (예: 1 → '1')
    if (idx == 0 || good(num][idx - 1], i + '0', a[idx -1])) {
      check[i] = 1;
      go(idx + 1, num + to_string(i));
      check[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  go(0, "");

  sort(ret.begin(), ret.end());

  cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
}