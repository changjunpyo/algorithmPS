#include <bits/stdc++.h>
using namespace std;
int main(){
	int L;
	cin >>L;
	bool arr[1001]={false,};
	while(L--){
		int x;
		cin >> x;
		arr[x] = true;
	}
	int ans1=0;
	int ans2=0;
	int t;
	cin >> t;
	int N = t;
	if (arr[N]){
		cout <<0<<"\n";
		return 0;
	}
	while(1){
		N++;
		if (arr[N])
			break;
		ans1++;
	}
	N = t;
	while(1){
		N--;
		if (N==0||arr[N])
			break;
		ans2++;
	}
	cout <<ans2*(ans1+1)+ ans1<<"\n";
}