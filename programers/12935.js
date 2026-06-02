// https://school.programmers.co.kr/learn/courses/30/lessons/12935
// 가장 작은 수 제거하기
function solution(arr) {
  let min = arr[0];
  let idx = 0;
  for (let i = 1; i < arr.length; i++) {
      if (arr[i] < min) {
          min = arr[i];
          idx = i;
      }
  }
  arr.splice(idx, 1);
  
  return arr.length === 0 ? [-1] : arr;
}

console.log(solution([4, 3, 2, 1])); // [4, 3, 2]
console.log(solution([10])); // [-1]


// 다른 사람 풀이
function anotherSolution(arr) {
    arr.splice(arr.indexOf(Math.min(...arr)),1);
    if(arr.length<1)return[-1];
    return arr;
}