include<bits/stdc++.h>
using namespace std;


int n;
string s;

bool check(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '(') stk.push(c);
        else{
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    if(check(s)) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}