#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;
const ll INF = 1e18;   
int n, c, a[1004];
vector<pair<int, int>> v; 
map<int, int> mp, mp_first; 

// [문제 유형]
// vector , map 사용법에 대한 예제로 보인다.

// 빈도순으로 정렬하는 함수
bool cmp(pair<int,int> a, pair<int, int> b){
  // 빈도수가 같다면 처음 등장한 순서로 정렬
	if(a.first == b.first){
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c; 
	for(int i = 0; i < n; i++){
		cin >> a[i];mp[a[i]]++;
		if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; 
	} 

  // 빈도수와 숫자를 저장
	for(auto it : mp){
		v.push_back({it.second, it.first});
	}
	sort(v.begin(), v.end(), cmp);
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";
		}
	} 
	 
	return 0;
}