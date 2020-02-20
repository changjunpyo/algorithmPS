#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	cin >>N>>M;
	int mn_package=987654321;
	int mn_string=987654321;
	while(M--){
		int x, y;
		cin >> x>>y;
		mn_package = min(mn_package,x);
		mn_string = min(mn_string,y);
	}
	if (mn_string*6 <= mn_package)
		cout << mn_string*N<<"\n";
	else{
		int ans = mn_package* (N/6);
		ans += min(mn_package, mn_string*(N%6));
		cout <<ans<<"\n";
	}
}