#include <bits/stdc++.h>
using namespace std;

// ===== 전역 변수 =====
const int INF = 987654321;          // 답의 초기값 (분할 불가 판정용 큰 수)
int n;                              // 구역 개수
int a[11];                          // a[i] = 구역 i의 인구 수
int m, temp;                        // 입력 임시 변수 (인접 개수, 인접 번호)
int ret = INF;                      // 최종 답 (최소 인구차)
int comp[11];                       // comp[i] = 구역 i의 그룹 번호 (0 또는 1)
int visited[11];                    // DFS 방문 체크 배열
vector<int> adj[11];                // 인접 리스트 (그래프)

// ===== DFS: 같은 그룹끼리 연결되어 있는지 + 인구합 계산 =====
// here  : 현재 방문 중인 구역
// value : 따라갈 그룹 번호 (이 값과 comp[there]가 같아야 이동)
// 반환값: {방문한 노드 개수, 인구합}
pair<int, int> dfs(int here, int value){
    visited[here] = 1;                          // 현재 노드 방문 처리
    pair<int, int> ret = {1, a[here]};          // 자기 자신 포함 (개수 1, 인구 a[here])

    for(int there : adj[here]){                 // 이웃 노드 모두 순회
        if(comp[there] != value) continue;      // 다른 그룹이면 건너뜀 (그룹 경계)
        if(visited[there]) continue;            // 이미 방문했으면 건너뜀
        pair<int, int> _temp = dfs(there, value);   // 재귀 호출
        ret.first  += _temp.first;              // 방문 노드 수 누적
        ret.second += _temp.second;             // 인구 누적
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ===== STEP 1: 입력 받기 =====
    cin >> n;                                   // 구역 개수
    for(int i = 1; i <= n; i++){
        cin >> a[i];                            // 구역별 인구
    }
    // 인접 정보: 각 구역 i마다 (개수 m) (인접 구역들)
    for(int i = 1; i <= n; i++){
        cin >> m;                               // 구역 i의 인접 개수
        for(int j = 0; j < m; j++){
            cin >> temp;                        // 인접 구역 번호
            adj[i].push_back(temp);             // i ↔ temp 양방향 연결
            adj[temp].push_back(i);             // (중복 저장되지만 visited로 처리됨)
        }
    }

    // ===== STEP 2: 비트마스크로 영역 나누는 것에 대한 모든 경우의 수 =====
    //
    // [무엇을 하는가]
    //   n개 구역을 두 그룹(A, B)으로 나누는 모든 방법을 i 하나로 표현해 시도한다.
    //   i를 2진수로 풀면 각 자리(비트)가 구역 1개의 소속을 의미한다.
    //     - 비트가 1 → 그룹A
    //     - 비트가 0 → 그룹B
    //
    // [예시] n=4, i=5 → 2진수 0101
    //     비트 위치 :  3 2 1 0
    //     i 값      :  0 1 0 1
    //                  │ │ │ └── 구역1 → 그룹A (비트=1)
    //                  │ │ └──── 구역2 → 그룹B (비트=0)
    //                  │ └────── 구역3 → 그룹A (비트=1)
    //                  └──────── 구역4 → 그룹B (비트=0)
    //
    // [반복 범위]  i = 1 ~ (1<<n) - 2
    //   (1 << n)     = 2^n        → 전체 분할 패턴 개수
    //   (1 << n) - 1 = 2^n - 1    → 모든 비트가 1 (예: n=4 → 1111 = 15)
    //
    //   i = 0       (0000) → 전부 그룹B, 그룹A가 비어있음 → 제외
    //   i = 2^n - 1 (1111) → 전부 그룹A, 그룹B가 비어있음 → 제외
    //   → 두 그룹 모두 최소 1개 구역을 가지도록 양 끝값 제외
    //   → 따라서 i는 1 부터 (1<<n)-2 까지만 검사
    //
    //   n=4 라면 i는 1, 2, 3, ..., 14 의 총 14가지 분할을 모두 시도한다.
    for(int i = 1; i < (1 << n) - 1; i++){
        fill(comp, comp + 11, 0);               // comp 배열 초기화
        fill(visited, visited + 11, 0);         // visited 배열 초기화

        int idx1 = -1, idx2 = -1;               // 각 그룹 DFS 시작점

        // ----- STEP 3: 비트 검사 → 그룹 배정 -----
        for(int j = 0; j < n; j++){
            // j번째 비트가 켜져있으면 그룹A(1), 아니면 그룹B(0)
            if(i & (1 << j)){
                comp[j + 1] = 1;                // 구역(j+1)을 그룹A로
                idx1 = j + 1;                   // 그룹A의 시작점 후보 (마지막 발견)
            } else {
                idx2 = j + 1;                   // 그룹B의 시작점 후보
            }
        }

        // ----- STEP 4: 각 그룹 DFS로 연결성 + 인구합 -----
        pair<int, int> comp1 = dfs(idx1, 1);    // 그룹A 탐색
        pair<int, int> comp2 = dfs(idx2, 0);    // 그룹B 탐색

        // ----- STEP 5: 유효성 검사 + 최솟값 갱신 -----
        // 두 그룹 방문 노드 합 == n  →  양쪽 모두 단일 연결 성분
        // (한쪽이라도 끊겨있으면 cnt 부족 → 무효)
        if(comp1.first + comp2.first == n){
            ret = min(ret, abs(comp1.second - comp2.second));   // 인구차 최소 갱신
        }
    }

    // ===== STEP 6: 출력 =====
    // 단 한 번도 유효한 분할이 없으면 -1, 있으면 최소 인구차
    cout << (ret == INF ? -1 : ret) << "\n";
}
