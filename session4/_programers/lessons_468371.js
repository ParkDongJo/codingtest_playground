// https://school.programmers.co.kr/learn/courses/30/lessons/468371
/*
  [제한 사항]
  signals 배열길이는 2 <= len <= 5
  signals 의 각 요소는 [G, Y, R] 로 구성되어 있다.
  G, Y, R 은 각각 number 타입으로 지속시간을 의미한다.
  G, Y, R 는 1<= {} <= 18
  G + Y + R 합은 3 <= sum <= 20
*/

// 최대공약수 (유클리드 호제법)
// b가 0이면 a가 최대공약수, 아니면 gcd(b, a%b)로 재귀
function gcd(a, b) {
  return b === 0 ? a : gcd(b, a % b);
}

// 최소공배수 = (a / 최대공약수) * b
// 나눗셈을 먼저 하여 오버플로우 방지
function lcm(a, b) {
  return (a / gcd(a, b)) * b;
}  

// function solution(signals) {
//   let answer = 0;
//   let sumGR = [];
//   let minY = -1;
//   // signals 배열을 순회하며 G, R 의 지속시간을 더하고, sumGR 배열에 저장한다.
//   // 동시에 가장 작은 Y 값을 minY 변수에 저장한다.
//   for (let i = 0; i < signals.length; i++) {
//     let [G, Y, R] = signals[i];
//     sumGR.push(G + R);
//     if (minY === -1 || Y < minY) {
//       minY = Y;
//     }
//   }

//   // sumGR 배열에 담긴 숫자들의 최소공배수를 구한다.
//   const result = sumGR.reduce((acc, curr) => lcm(acc, curr), 1);
//   // 최소 공배수가 0이면 -1을 반환한다.
//   if (result === 0) {
//     return -1;
//   }
  
//   // 구해진 최소 공배수에 minY 값을 더하고, answer 변수에 저장한다.
//   answer = result + minY;
//   return answer;
// }

function solution(signals) {
  // Ai 작성

  // 각 신호등의 G(초록) 지속시간, Y(노랑) 지속시간, 전체 주기(G+Y+R)를 추출
  const cycles = signals.map(([G, Y, R]) => ({ g: G, y: Y, cycle: G + Y + R }));

  // 탐색 범위: 모든 주기의 최소공배수 (이후는 동일 패턴 반복)
  const limit = cycles.reduce((acc, c) => lcm(acc, c.cycle), 1);

  // t=1부터 limit까지 순회하며 모든 신호가 동시에 Y인 시점을 찾는다
  for (let t = 1; t <= limit; t++) {
    const allYellow = cycles.every(({ g, y, cycle }) => {
      // t는 1부터 시작하므로 (t-1)로 0-indexed 위치를 구한다
      // 주기 내 위치: 0~(G-1)은 초록, G~(G+Y-1)은 노랑, 그 이후는 빨강
      const pos = (t - 1) % cycle;
      return pos >= g && pos < g + y;
    });
    // 모든 신호가 노랑이면 해당 시점 반환
    if (allYellow) return t;
  }

  // limit까지 찾지 못하면 동시에 Y인 시점이 없음
  return -1;
}

console.log(solution([[2,1,2], [5,1,1]]));  // 기대값 : 13
console.log(solution([[2,3,2], [3,1,3], [2,1,1]]));  // 기대값 : 11
console.log(solution([[3,3,3], [5,4,2], [2,1,2]]));  // 기대값 : 193
console.log(solution([[1,1,4], [2,1,3], [3,1,2], [4,1,1]]));  // 기대값 : -1
