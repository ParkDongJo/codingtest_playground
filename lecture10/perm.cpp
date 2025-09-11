// 조합 - nCr = nPr / r! = n! / (n-r)! * r!
//     - 순서가 상관 없는 경우
// 순열 - nPr = n! / (n-r)!
//     - 순서가 상관 있는 경우

#include <bits/stdc++.h>
using namespace std;

// int main() {
//     // vector<int> v = {1, 2, 3, 4, 5};
//     int a [] = {1, 3, 2, 4, 5};

//     // next_permutation() 을 사용하기 위해, 정렬이 되어 있어야 한다.
//     // next_permutation() 오름차순 기반으로 순열을 생성한다.
//     sort(&a[0], &a[0] + 5);
//     do {
//         for (int i : a) {
//             cout << a[i] << " ";
//         }
//         cout << "\n";
//     } while (next_permutation(&a[0], &a[0] + 5));
//     // } while (next_permutation(a, a + 5));
//     // } while (next_permutation(v.begin(), v.end()));
//     return 0;
// }


// 만약 이중에 2개만 뽑는 순열을 구하고 싶다면?
int main() {
    // vector<int> v = {1, 2, 3, 4, 5};
    int a [] = {1, 3, 2, 4, 5};

    // next_permutation() 을 사용하기 위해, 정렬이 되어 있어야 한다.
    // next_permutation() 오름차순 기반으로 순열을 생성한다.
    sort(&a[0], &a[0] + 5);
    do {
        for (int i = 0; i < 2; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(&a[0], &a[0] + 5));
    return 0;
}