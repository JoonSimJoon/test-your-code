#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int n;
long long jun;
vector<int> v;
 
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		//준원이 공격력 입력
		if (i == 0) {
			cin >> jun;
		}
		//나머지 공격력 입력
		else {
			int data;
			cin >> data;
			v.push_back(data);
		}
	}
}
 
bool alive() {
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size();i++) {
		int enemy = v[i];
		if (jun <= enemy) {
			return false;
		}
		else{
			jun += enemy;
		}
 
	}
 
	return true;
}
 
void solve() {
	input();
	if (alive()) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	solve();
	return 0;
}
