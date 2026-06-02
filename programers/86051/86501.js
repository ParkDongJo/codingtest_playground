function solution(numbers) {
    var answer = 0;
    
    for (let i = 0; i < 10; i++) {
      if (numbers.find(num => num === i)) {
        continue;
      } else {
        answer += i;
      }
    }
    return answer;
}