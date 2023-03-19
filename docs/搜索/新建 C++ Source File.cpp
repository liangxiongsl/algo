#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int t = 0;
	for(int i=1; i<=n-2; ++i){
		for(int j=i; j<=n-(1+i) && j<=n-i-j; ++t, ++j){
			printf("%d %d %d\n", i, j, n-i-j);
		}
	}
	cout << t << '\n';
	solve();
}

signed main(){
	solve();
}

