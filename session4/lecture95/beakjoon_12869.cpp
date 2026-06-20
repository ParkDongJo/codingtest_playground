#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dp[64][64][64];                  // (사용 안 함) DP용 배열
int a[3];                            // 입력받은 SCV 체력 (최대 3개)
int n;                               // SCV 개수
int visited[64][64][64];             // 상태 (a, b, c)까지 도달하는데 필요한 공격 횟수 + 1

// 뮤탈리스크 공격: 한 번에 3개 SCV에 9/3/1 데미지를 다른 분배로 입힘
// 6가지 순열 (3! = 6)
int _a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};

struct A {
    int a, b, c;     // SCV 3대의 현재 체력 상태
};

queue<A> q;

// BFS로 (a, b, c) 상태에서 (0, 0, 0)까지 가는 최소 공격 횟수 탐색
int solve(int a, int b, int c) {
    visited[a][b][c] = 1;            // 시작 상태 = 1 (나중에 -1로 보정)
    q.push({a, b, c});

    while (q.size()) {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        // 모든 SCV 파괴 상태에 도달했으면 종료
        if (visited[0][0][0]) break;

        // 6가지 데미지 분배 시도
        for (int i = 0; i < 6; i++) {
            // 체력은 음수가 될 수 없으므로 max(0, ...) 처리
            // → 동일 상태로 수렴시켜 탐색 공간 축소
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);

            if (visited[na][nb][nc]) continue;       // 이미 방문한 상태는 스킵
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }

    // 시작 상태를 1로 잡았으므로 실제 공격 횟수는 -1
    return visited[0][0][0] - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    // n < 3인 경우 나머지 a[]는 0으로 초기화되어 있음 (전역변수)

    cout << solve(a[0], a[1], a[2]) << "\n";
    return 0;
}
