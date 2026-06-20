// BOJ 4179 - 불!
// 미로(J: 지훈, F: 불, #: 벽, .: 빈칸)에서 지훈이 경계 밖으로 탈출하는 최소 시간.
// 매 분마다 불은 인접 칸으로 번지고, 지훈도 인접 칸으로 이동한다.
// 풀이: 멀티소스 BFS로 불의 도달 시간을 먼저 계산한 뒤, 지훈의 BFS에서
//       각 칸의 도달 시간이 불보다 빠른 경우에만 이동 가능.
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
char a[1004][1004];                          // 미로 격자
int n, m, sx, sy;                            // 행/열 크기, 지훈 시작 위치 (sy=행, sx=열)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};                   // 4방향(상,좌,하,우) 이동 벡터
int ret;                                     // 탈출 시간 (0이면 불가능)
int fire_check[1004][1004];                  // 불이 각 칸에 도달하는 최소 시간 (도달 불가면 INF)
int person_check[1004][1004];                // 지훈이 각 칸에 도달하는 최소 시간 (0이면 미방문)

bool in(int a, int b) {
    // 격자 범위 안에 있는 좌표인지 확인
    return 0 <= a && a < n && 0 <= b && b < m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    queue<pair<int, int>> q;                 // BFS 공용 큐 (불 BFS → 지훈 BFS 순서로 재사용)
    cin >> n >> m;

    // 불이 도달하지 못하는 칸과 아직 계산하지 않은 칸을 구분하기 위해 INF로 초기화
    // (person_check는 0이 미방문 의미라서 별도 초기화 불필요)
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'F') {
                // 불('F') 위치: 도달 시간 1로 설정 후 큐에 삽입 (멀티소스 BFS)
                fire_check[i][j] = 1;
                q.push({i, j});
            } else if (a[i][j] == 'J') {
                // 지훈('J') 시작 위치 저장
                sy = i; sx = j;
            }
        }
    }

    // 1단계 BFS: 불 전파 시뮬레이션
    // 모든 불 시작점에서 동시에 퍼져나가며 각 칸의 최소 도달 시간 계산
    // 시작 시간을 1로 두었기 때문에 다음 칸은 현재 시간 + 1이 된다.
    while (q.size()) {
        auto [y, x] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx)) continue;
            // 이미 방문했거나 벽('#')이면 스킵
            if (fire_check[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // 2단계 BFS: 지훈 이동 시뮬레이션
    // 경계(가장자리)에 도달하면 탈출 성공
    // 불이 먼저 또는 같은 시간에 도착하는 칸은 이동할 수 없다.
    // 시작 시간을 1로 두어 person_check==0을 "미방문" 표식으로 사용한다.
    person_check[sy][sx] = 1;
    q.push({sy, sx});

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 경계에 도달했으면 탈출 성공 → 시간 저장 후 종료
        if (x == m - 1 || y == n - 1 || x == 0 || y == 0) {
            ret = person_check[y][x];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx)) continue;
            // 이미 방문했거나 벽이면 스킵
            if (person_check[ny][nx] || a[ny][nx] == '#') continue;
            // 지훈 도착 시간보다 불 도착 시간이 빠르거나 같으면 이동 불가
            if (fire_check[ny][nx] <= person_check[y][x] + 1) continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
            
        }
    }

    // person_check를 1부터 시작했으므로 ret이 곧 "이동한 분 수 + 1"이 되는데,
    // 시작칸 자체를 1분으로 보고 누적했으니 그대로 출력하면 정답이다.
    if (ret != 0) cout << ret << "\n";
    else cout << "IMPOSSIBLE\n";

    return 0;
}
/*
3 3
...
.J.
...
*/
