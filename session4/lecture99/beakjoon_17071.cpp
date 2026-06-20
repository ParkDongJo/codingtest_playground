#include <bits/stdc++.h>
using namespace std;
const int max_n = 500000;  // 좌표 최댓값 (문제 제약)

// visited[parity][pos]: parity(턴 % 2)에 해당하는 시점에 pos에 도달 가능한지
// 핵심 관찰: 어떤 위치에 t턴에 도달했다면, +1/-1을 반복해서 t+2, t+4, ... 에도 항상 도달 가능
// → 따라서 "도달 가능 여부"는 짝/홀 패리티만 기록하면 충분
int visited[2][max_n + 4], a, b, ok, turn = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;  // a: 수빈이 위치, b: 동생 위치
    if(a == b){cout << 0 << "\n"; return 0;}  // 0초에 이미 같은 위치
    queue<int> q;
    visited[0][a] = 1;  // 0턴(짝수 패리티)에서 a에 위치 — 1은 "방문 표시"용 truthy 값
    q.push(a);
    while(q.size()){
        // 동생 이동: t턴째에는 누적 turn 만큼 이동 (1 + 2 + 3 + ... 의 점진 가속)
        b += turn;
        if(b > max_n)break;  // 동생이 좌표 범위를 벗어나면 더 이상 만날 수 없음
        // 동생의 현재 위치 b가 현재 턴 패리티로 수빈이가 이미 도달 가능했던 칸이면 성공
        // (수빈이는 같은 패리티 안에서 자유롭게 시간을 보낼 수 있으므로)
        if(visited[turn % 2][b]) {
            ok = true;
            break;
        }
        int qSize = q.size();  // 이번 레벨(이전 턴까지)에 큐에 쌓인 노드 수만 이번에 확장

        for(int i = 0; i < qSize; i++){
            int x = q.front(); q.pop();
            // 수빈이의 3가지 이동: -1, +1, *2
            for(int nx : {x + 1, x - 1, x * 2}){
                // 범위 밖이거나 현재 패리티로 이미 방문한 곳이면 스킵
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
                // 방문 표시: 이전 턴 패리티의 x값(거리/카운트)에 +1
                // (사실 도달 여부만 중요하므로 비제로면 충분 — 값 자체는 사용하지 않음)
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                if(nx == b){
                    // 확장 도중 동생 위치와 정확히 일치하는 경우도 즉시 성공
                    ok = 1; break;
                }
                q.push(nx);
            }
            if(ok)break;
        }
        if(ok)break;
        turn++;  // 다음 턴으로
    }
    if(ok) cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;
}
