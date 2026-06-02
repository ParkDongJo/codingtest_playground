// https://school.programmers.co.kr/learn/courses/30/lessons/12934?language=javascript

function solution(n) {
    var answer = 0;
    //  Math.sqrt(n) : n의 제곱근
    //  Number.isInteger(x) : x가 정수인지 판별
    const sqrt = Math.sqrt(n);
    if (Number.isInteger(sqrt)) {
        answer = Math.pow(sqrt + 1, 2);
    } else {
        answer = -1;
    }
    return answer;
}