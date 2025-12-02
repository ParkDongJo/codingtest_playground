# 처음 나의 풀이

입력으로 들어오는 패터는 아래와 같음
{prefix}\*{subfix}

prefix 와 subfix 는 각각 한글자이고 첫글자와 끝글자이다.

이후 들어오는 문자열의 첫 글자와 prefix 를 비교하고 끝글자와 subfix 를 비교해서 같으면 DA, 다르면 NE 으로 한다.

# 나의 실책

- 예제가 양쪽 한글자라고 해서 한글자만 생각함 (문제에서 앞뒤가 한글자라는 말은 없음)

- ab\*ab 일때 최소한 abab 가 되어야한다. 이 케이스는 반례가 될 수도 있다.

# 큰돌님의 풀이

- - 를 기점으로 prefix 와 subfix를 구한다.

  * s.find('\*') 로 별표위치
  * s.substr(0, pos) 로 prefix
  * s.substr(pos + 1) 로 subfix

- 입력값의 prefix 와 subfix 를 비교해서 같으면 DA
- 다르면 NE

- 반례! \*가 없으면서 prefix 가 동일하고 맞는 경우가 있다!!! (이건 문제의 경험이 많아야 할것 같다)
