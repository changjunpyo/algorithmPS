#include <bits/stdc++.h>
using namespace std;

long long binary_search(long long k, long long  x, long long  y, long long  z){
	long long  lo =1;
	long long  hi =k;
	while (lo+1 < hi){
		long long  mid = (lo+hi)/2;
		if (z > (mid+y)*100/(x+mid))
			lo = mid;
		else
			hi = mid;

	}
	return hi;
}

int main(){
	long long X,Y;
	cin >>X >>Y;

	long long  Z = 100*Y/X;
	if (Z >= 99){
		cout << -1<<"\n";  
		return 0;
	}
	long long  k= X/(99-Z) +1;
	for (int i=k; ; i--){
		if (Z ==(i+Y)*100/(X+i)){
			k=i;
			break;
		}
	}
	long long  ans = binary_search(k, X,Y, Z+1);
	cout <<ans<<"\n";
}