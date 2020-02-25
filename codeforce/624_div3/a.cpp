#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main(){
	fastio
	int t;
	cin >>t;

	while(t--){
		int ans=0;
		int a,b;
		cin >>a >>b;
		int c = b-a;
		if (c==0){
			cout <<0<<"\n";
			continue;
		}
		if (c >0){
			if (c %2 ==1)
				cout <<1<<"\n";
			else
				cout <<2 <<"\n";
		}
		else{
			if ((a-b)%2 ==1)
				cout <<2<<"\n";
			else
				cout <<1<<"\n";
		}
	}
}