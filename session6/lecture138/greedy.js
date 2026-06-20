let result = 0;
let totalAmount = 12100;

const c = [[10000, 5], [5000, 5], [1000, 5], [1000, 7], [100, 5]];

// rbegin, rend 는 역순으로 정렬하는 것
// 벡터는 {first, second} 중 어떤 기준으로 정렬하는가?
// first 기준으로 정렬하는 것

// 만약 second 기준으로 정렬하고 싶다면?
// sort(c.begin(), c.end(), (a, b) => a[1] - b[1]);

c.sort((a, b) => b[0] - a[0]);

// auto &coin : c 는 coin 을 참조하는 것
// 왜 참조하는가?
// 참조하면 값을 변경할 수 있기 때문에
// auto 키워드는 타입을 자동으로 추론하는 것
// 주로 반복문에서 사용된다.
for (const coin of c) {
  while (totalAmount >= coin[0]) {
    totalAmount -= coin[0];
    coin[1]--;
    result++;
  }
}
if (totalAmount === 0)
  console.log(result);
else
  console.log("impossible");
