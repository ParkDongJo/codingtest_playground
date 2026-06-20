include <bits/stdc++.h>
using namespace std;
int n, m, t, a[54][54], temp[54][54];
vector<pair<int, int>> v1, v2;

const int dy1[] = {0, -1, 0, 1};
const int dx1[] = {1, 0, -1, 0};
const int dy2[] = {0, 1, 0, -1};
const int dx2[] = {1, 0, -1, 0};

// 먼지가 확산되는 것을 시뮬레이션하는 함수이다. 먼지가 확산되는 규칙은 다음과 같다.
// 1. 먼지는 네 방향으로 확산된다.
// 2. 확산되는 먼지의 양은 (현재 칸의 먼지 양) / 5 이다. (소수점 아래는 버린다)
// 3. 확산되는 먼지가 칸에 존재하는 먼지 양보다 많을 수는 없다.
// 4. 공기청정기가 있는 칸으로는 확산되지 않는다.
void mise_spread(int dy[], int dx[]) {
  fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
  queue<pair<int, int>> q;

  for(int i = 0; i < t; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] != -1 && a[i][j] ) {
        q.push({i, j});
      }
    }
  }

  // 먼지가 확산되는 것을 시뮬레이션한다.
  while(q.size()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    int spread = a[y][x] / 5;

    for(int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];

      // ny, nx가 범위를 벗어나면 건너뛴다.
      if (ny < 0 || ny >= t || nx < 0 || nx >= m) continue;
      // 공기청정기가 있는 칸이라면 건너뛴다.
      if (a[ny][nx] == -1) continue;

      // 먼지가 확산되는 경우, temp[ny][nx]에 확산되는 먼지의 양을 더해준다.
      temp[ny][nx] += spread;
      // 먼지가 확산되는 경우, a[y][x]에 확산되는 먼지의 양을 빼준다.
      a[y][x] -= spread;
    }
  }

  // 먼지가 확산된 결과를 a에 반영한다.
  // 먼지가 확산된 결과는 temp에 저장되어 있다. temp의 값을 a에 더해준다.
  for(int i = 0; i < t; i++){
    for(int j = 0; j < m; j++){
      a[i][j] += temp[i][j];
    }
  }
  return;
}

// 공기청정기가 바람을 내뿜기 전에, 공기청정기가 바람을 내뿜는 경로를 미리 계산해놓는다.
// 결과값은 v1, v2에 저장된다. (v1은 위쪽 공기청정기의 바람 경로, v2는 아래쪽 공기청정기의 바람 경로)
vector<pair<int, int>> ready_clean(int sy, int sx, int dy[], int dx[]) {
  vector<pair<int, int>> v;
  int cnt = 0;
  int y = sy, x = sx;

  while(true) {
    int ny = y + dy[cnt];
    int nx = x + dx[cnt];

    if (ny < 0 || ny >= t || nx < 0 || nx >= m) {
      cnt++;
      ny = y + dy[cnt];
      nx = x + dx[cnt];
    }
    if (ny == sy && nx == sx) break;

    y = ny;
    x = nx;
    v.push_back({y, x});
  }
  return v;
}

// 공기청정기가 바람을 내뿜는 경로에 대해서, 공기청정기가 바람을 내뿜는 경로를 따라 먼지를 이동시킨다.
void do_clean(vector<pair<int, int>> &v) {
  // v의 마지막 원소부터 역순으로, 먼지를 이동시킨다.
  for(int i = v.size() - 1; i > 0; i--) {
    a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
  }
  // v의 첫 번째 원소는 공기청정기 바로 옆이므로, 먼지가 없는 상태가 된다.
  a[v[0].first][v[0].second] = 0;
  return;
}

int main() {
  cin >> n >> m >> t;
  bool flag = true;

  for(int i = 0; i < t; i++){
    for(int j = 0; j < m; j++){
      cin >> a[i][j];
      if (a[i][j] == -1) {
        if (flag) {
          v1 = ready_clean(i, j, dy1, dx1);
          flag = false;
        } else {
          v2 = ready_clean(i, j, dy2, dx2);
        }
      }
    }
  }

  // t초 동안 먼지가 확산되고, 공기청정기가 바람을 내뿜는 것을 시뮬레이션한다.
  while(t--) {
    mise_spread(dy, dx);
    // 공기청정기가 바람을 내뿜는 경로를 따라 먼지를 이동시킨다.
    do_clean(v1);
    do_clean(v2);
  }

  // t초가 지난 후, 방에 남아있는 먼지의 양을 계산한다.
  for(int i = 0; i < t; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] != -1) {
        n += a[i][j];
      }
    }
  }
  cout << n << "\n";
  return 0;
}