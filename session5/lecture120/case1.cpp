#include <bits/stdc++.h>
using namespace std;

const int n = 4;

int main() {
    string a[n] = {"사과", "딸기", "포도", "배"};

    // 모든 부분집합 열거: i = 0 ~ 15 (2^4 = 16개)
    for(int i = 0; i < (1 << n); i++){
        string ret = "";
        for(int j = 0; j < n; j++){
            // i의 j번째 비트가 1이면 a[j]를 부분집합에 포함
            if(i & (1 << j)){
                ret += (a[j] + " ");
            }
        }
        cout << ret << '\n';
    }
    return 0;
}

/*
출력 (i=0인 공집합은 빈 줄):

사과
딸기
사과 딸기
포도
사과 포도
딸기 포도
사과 딸기 포도
배
사과 배
딸기 배
사과 딸기 배
포도 배
사과 포도 배
딸기 포도 배
사과 딸기 포도 배
*/
