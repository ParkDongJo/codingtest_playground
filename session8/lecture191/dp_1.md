# DP 의 조건

1. 초기화 (Initialization)

```
memset(dp, -1, sizeof(dp));
```

2. 기저 사례 (Base Case)

```
if (cnt < 0) return -1e9;
```

```
if (idx == n) return 0;
```

3. 메모이제이션 (Memoization)

```
int &ret = dp[idx][tree][cnt];
if (ret != -1) return ret;
```

4.로직