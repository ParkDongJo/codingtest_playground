// d 는 direction 의 약자
// 방향키라고 생각하자!!
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let y = 0, x = 0;

for (let i = 0; i < 4; i++) {
  const ny = y + dy[i];
  const nx = x + dx[i];
  console.log(ny + " " + nx);
}
