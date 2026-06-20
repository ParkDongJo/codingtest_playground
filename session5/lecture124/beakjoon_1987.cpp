#include <bits/stdc++.h>
using namespace std;
int R, C, ret, ny, nx, visited[30];
char a[21][21];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = { 0, 1, 0, -1}; 

void go(int y, int x, int cnt){
    ret = max(ret, cnt);
    for(int i = 0; i < 4; i++){
      // lecture102 에서 풀었던 코드를 비트마스킹 기법으로 다시 작성해본다.
      // ny = y + dy[i], nx = x + dx[i];
      // if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      
      // int next = (int)(a[ny][nx] - 'A');
      // if(visited[next] == 0){
      //     visited[next] = 1; 
      //     go(ny, nx, cnt + 1);
      //     visited[next] = 0;  
      // } 

        ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int _next = (1 << (int)(a[ny][nx] - 'A'));

        // num & _next 는 num과 _next가 겹치는 부분이 있는지 확인하는 것이다.
        // 겹치는 부분이 없다면 (num & _next) == 0 이
        // 겹치는 부분이 있다면 (num & _next) != 0 이 된다. 
        if((num & _next) == 0) {
          go(ny, nx, num | _next, cnt + 1);
        }
    }
    return;
}
int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }
    visited[(int)a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret << '\n';
    return 0;
}
