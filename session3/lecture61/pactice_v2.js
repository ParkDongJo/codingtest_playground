/*
8방향에서는 아래와 같다!! 왜 그런지 인접행렬을 바탕으로 생각을 해보자



*/

const dy = [-1, -1, 0, 1, 1, 1, 0, -1];
const dx = [0, 1, 1, 1, 0, -1, -1, -1];

let y = 0, x = 0;
for (let i = 0; i < 8; i++) {
  const ny = y + dy[i];
  const nx = x + dx[i];
  console.log(ny + " : " + nx);
}
