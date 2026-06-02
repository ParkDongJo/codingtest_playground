// 조합 - nCr = nPr / r! = n! / (n-r)! * r!
//     - 순서가 상관 없는 경우
// 순열 - nPr = n! / (n-r)!
//     - 순서가 상관 있는 경우

function nextPermutation(arr) {
    let i = arr.length - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) i--;
    if (i < 0) return false;
    let j = arr.length - 1;
    while (arr[j] <= arr[i]) j--;
    [arr[i], arr[j]] = [arr[j], arr[i]];
    let l = i + 1, r = arr.length - 1;
    while (l < r) { [arr[l], arr[r]] = [arr[r], arr[l]]; l++; r--; }
    return true;
}

// 만약 이중에 2개만 뽑는 순열을 구하고 싶다면?
const a = [1, 3, 2, 4, 5];

// next_permutation() 을 사용하기 위해, 정렬이 되어 있어야 한다.
// next_permutation() 오름차순 기반으로 순열을 생성한다.
a.sort((a, b) => a - b);
do {
    let output = '';
    for (let i = 0; i < 2; i++) {
        output += a[i] + ' ';
    }
    console.log(output.trim());
} while (nextPermutation(a));
