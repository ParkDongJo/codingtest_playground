// 백준 17471 - 게리맨더링
// 비트마스킹으로 모든 분할 시도 + DFS로 연결성/인구합 검사

const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

// ===== STEP 1: 입력 파싱 =====
const n = Number(input[0]);                          // 구역 개수
const a = [0, ...input[1].split(" ").map(Number)];   // 1-indexed: a[1..n] = 인구

// 인접 리스트 (1-indexed)
const adj = Array.from({ length: n + 1 }, () => []);
for (let i = 1; i <= n; i++) {
    const tokens = input[1 + i].split(" ").map(Number);
    const m = tokens[0];                             // 인접 개수
    for (let j = 1; j <= m; j++) {
        const t = tokens[j];                         // 인접 구역 번호
        adj[i].push(t);
        adj[t].push(i);                              // 양방향 (중복 발생 가능 — visited로 처리)
    }
}

// ===== 전역 상태 =====
const INF = 987654321;
let ret = INF;                                       // 최소 인구차
const comp = new Array(n + 1).fill(0);               // 그룹 번호 (0 or 1)
const visited = new Array(n + 1).fill(0);            // DFS 방문 체크

// ===== DFS: 같은 그룹 연결성 + 인구합 =====
// here  : 현재 노드
// value : 따라갈 그룹 번호 (comp[there] === value 일 때만 이동)
// 반환  : [방문 노드 수, 인구합]
function dfs(here, value) {
    visited[here] = 1;
    let cnt = 1;
    let sum = a[here];

    for (const there of adj[here]) {
        if (comp[there] !== value) continue;         // 다른 그룹 → 차단
        if (visited[there]) continue;                // 이미 방문 → skip
        const [c, s] = dfs(there, value);
        cnt += c;
        sum += s;
    }
    return [cnt, sum];
}

// ===== STEP 2: 비트마스크로 모든 분할 시도 =====
//
// i를 2진수로 풀면 각 비트가 구역 1개의 그룹 소속.
//   비트 = 1 → 그룹A
//   비트 = 0 → 그룹B
//
// 범위 1 ~ (1<<n) - 2 : 양 끝(전부0, 전부1) 제외 → 두 그룹 모두 비지 않도록
for (let i = 1; i < (1 << n) - 1; i++) {
    comp.fill(0);
    visited.fill(0);

    let idx1 = -1, idx2 = -1;                        // 각 그룹 DFS 시작점

    // ----- STEP 3: 비트 검사 → 그룹 배정 -----
    for (let j = 0; j < n; j++) {
        if (i & (1 << j)) {
            comp[j + 1] = 1;                         // 구역(j+1)을 그룹A
            idx1 = j + 1;
        } else {
            idx2 = j + 1;                            // 그룹B 시작점 후보
        }
    }

    // ----- STEP 4: 각 그룹 DFS -----
    const [cnt1, sum1] = dfs(idx1, 1);               // 그룹A
    const [cnt2, sum2] = dfs(idx2, 0);               // 그룹B

    // ----- STEP 5: 유효성 검사 + 최솟값 갱신 -----
    // cnt1 + cnt2 === n → 두 그룹 모두 단일 연결 성분
    if (cnt1 + cnt2 === n) {
        ret = Math.min(ret, Math.abs(sum1 - sum2));
    }
}

// ===== STEP 6: 출력 =====
console.log(ret === INF ? -1 : ret);
