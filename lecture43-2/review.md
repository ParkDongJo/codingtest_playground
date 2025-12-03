# 강의 보기 전

포켓몬 갯수 N
문제 갯수 M

N 만큼 반복문 돌면서, 포켓몬을 배열에 넣는다.

그리고 배열을 돌면서, 나의 특정 해시 함수를 활용해서

- 인덱스 숫자 : 텍스트
- 텍스트 : 인덱스 숫자

이렇게 각각 모두 키를 인덱스 숫자 와 텍스트 모두 만들어서 해시맵에 넣는다.
문제 갯수 만큼 돌면서, 해시맵에 값을 바로바로 가져온다.

# 강의

atoi()

```c++
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    char s[] = "123";
    int num = atoi(s);
    std::cout << "변환된 숫자: " << num << std::endl; // 출력: 변환된 숫자: 123

    std::string str = "456";
    int num = atoi(str.c_str()); // c_str()을 사용하여 char*로 변환
    std::cout << "변환된 숫자: " << num << std::endl; // 출력: 변환된 숫자: 456
    return 0;
}
```

atoi()
