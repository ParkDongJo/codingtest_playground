#include <bits/stdc++.h>
using namespace std;

const int n = 4;
string a[n] = {"사과", "딸기", "포도", "배"};

// num의 비트가 켜진 위치에 해당하는 과일들을 출력
void go(int num){
    string ret = "";
    for(int i = 0; i < n; i++){
        if(num & (1 << i)) ret += a[i] + " ";
    }
    cout << ret << '\n';
}

int main() {
    // "사과(비트0)"는 항상 포함하고, 추가로 1개씩만 함께 선택
    //   i=1 → 1 | (1<<1) = 0b0011 → 사과 딸기
    //   i=2 → 1 | (1<<2) = 0b0101 → 사과 포도
    //   i=3 → 1 | (1<<3) = 0b1001 → 사과 배
    for(int i = 1; i < n; i++){
        go(1 | (1 << i));
    }
    return 0;
}

/*
출력:
사과 딸기
사과 포도
사과 배
*/
