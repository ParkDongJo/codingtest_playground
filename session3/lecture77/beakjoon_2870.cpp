#include <bits/stdc++.h>
using namespace std;   
int n; 
vector<string> v; 
string s, ret;
void go(){   
	while(true){  
		if(ret.size() && ret.front() == '0')ret.erase(ret.begin()); 
		else break;
	}
	if(ret.size() == 0) ret = "0"; 
	v.push_back(ret);
	ret = "";  
}

/*
해당 cmp를 기반으로 하는 sort()원리는 다음과 같습니다.

sort()의 원리
sort()는 각각의 요소들을  cmp함수가 true 가 뜨는 “요소들의 순서”로 바꿔줍니다.  

#include<bits/stdc++.h>
using namespace std;   
bool cmp(int a, int b){
return a < b; 
} 
vector<int> v = {3, 10, 4, 11};
int main(){
sort(v.begin(), v.end(), cmp);
for(int i : v) cout << i << " ";
}

예를 들어 {3, 10, 4, 11}이 있다고 했을 때

10과 4는 a < b가 false이기 때문에 이를 바꿔서 4, 10으로 만들고 다른 요소들도 그런지를 확인합니다. 

이런 과정들을 반복해서 {3, 4, 10, 11}이라는 집합을 만듭니다. 즉, 모든 요소들이 a < b라는 조건식을 충족시키는 집합으로 만드는 것이죠.
*/
bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
int main () {
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
	 	ret = "";
		for(int j = 0; j < s.size(); j++){
			if(s[j] < 65)ret += s[j];
			else if(ret.size()) go(); 
		}
		if(ret.size()) go(); 
	}
	sort(v.begin(), v.end(), cmp);
	for(string i : v)cout << i << "\n"; 
	return 0;
}