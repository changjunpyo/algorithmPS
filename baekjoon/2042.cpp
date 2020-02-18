#include <bits/stdc++.h>
using namespace std;

void update(vector<long long> &tree, int i, long long diff){
	while(i <tree.size()){
		tree[i] += diff;
		i += (i &-i);
	}
}

long long sum(vector<long long> &tree , int i){
	long long ans = 0;
	while(i >0){
		ans += tree[i];
		i -= (i& -i);
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k;
	cin >>n>>m>>k;
	vector<long long> a(n+1);
	vector<long long> t(n+1);
	for (int i=1; i<=n; i++){
		cin >>a[i];
		update(t,i,a[i]);
	}

	for (int i=0; i<m+k; i++){
		int x,y,z;

		cin >>x;
		if (x == 1){
			cin >>y>>z;
			update(t,y,z-a[y]);
			a[y] = z;
		}
		else{
			cin >>y >>z;
			cout <<sum(t,z)- sum(t,y-1)<<"\n";
		}
	}
}