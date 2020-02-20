#include <bits/stdc++.h>
using namespace std;

void update(vector<long long> &t, int i, long long diff){
	while(i <t.size()){
		t[i] += diff;
		i += (i & -i);
	}
}

long long sum (vector<long long > &t, int i){
	long long ans =0;
	while(i >0){
		ans += t[i];
		i -= (i & -i);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;		
	cin >>N;
	vector<long long> a(1000001,0);
	vector<long long> b(N+1, 0);
	vector<long long > t(N+1, 0);

	for (int i=1; i<=N; i++){
		int x;
		cin >>x;
		a[x] =i;
	}

	for (int i=1; i<=N; i++){
		int x;
		cin >>x;
		b[a[x]] = i;
	}
	long long ans =0;
	for (int i=1; i<=N; i++){
		ans +=(sum(t,N)- sum(t,b[i]));
		update(t, b[i],1);
	}
	cout <<ans<<"\n";


}