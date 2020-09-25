#include <iostream>
using namespace std;

int main(){
	int N,M;
	cin >>N >> M;
	int a[10000];
	for (int i=0; i<M; i++){
		cin >>a[i];
	}
	if (N <= M) {
		cout << N <<"\n";
		return 0;
	}

	long long l = 0;
	long long r = 40LL*2000000000LL;
	while(l< r){
		long long mid = l+ (r-l)/2;
		long long cnt = M;
		for (int i=0; i<M; i++){
			cnt += mid/a[i];
		}
		if (cnt < N){
			l = mid+1;
		} else{
			r = mid;
		}
	}
	int count =0;
	for (int i=0; i<M; i++) count += (l-1)/a[i] + 1;
	for (int i=0; i<M; i++){

		if (l % a[i] == 0) {
			count += 1;
			if (count == N) {
				cout <<i+1<<"\n";
				return 0;
			}
		}
	}

}