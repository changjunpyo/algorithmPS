#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >>N;

	for (int i=1; i<N; i++){
		int sum =i;
		int t = i;
		while(t){
			sum += t%10;
			t/=10;
		}
		if (sum == N){
			cout <<i<<"\n";
			return 0;
		}
	}
	cout <<0<<"\n";
}