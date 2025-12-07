# 인접행렬

bool 타입의 정사각형 2차원 행렬

arr[from][to] = 1 | 0

```c++
bool arr[4][4] = {
  { 0, 1, 1, 0},
  { 1, 0, 1, 0},
  { 1, 1, 0, 0},
  { 1, 0, 0, 0 }
}

// from 를 중심으로 to를 확인
for (int from = 0; from < n; from++) {
  for (int to = 0; to < n; to++) {
    if (arr[from][to]) {
      cout << from << "부터" << to "까지 경로가 있다"
    }
  }
}

// to 를 중심으로 from 확인
for (int to = 0; to < n; to++) {
  for (int from = 0; from < n; from++) {
    if (arr[from][to]) {
      cout << from << "부터" << to "까지 경로가 있다"
    }
  }
}
```
