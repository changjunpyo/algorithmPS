#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &tree, int i, int diff){
	while(i <tree.size()){
		tree[i] += diff;
		i += (i &-i);
	}
}

int sum(vector<int> &tree , int i){
	int ans = 0;
	while(i >0){
		ans += tree[i];
		i -= (i& -i);
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >>T;
	while(T--){
		int n,m;
		cin >> n;
		vector<int> h(n+1,0);
		for (int i=1; i<=n; i++){
			h[i]= n-i+1;
		}
		cin >>m;
		vector<int> t(m+n+5,0);
		for (int i=1; i<=n; i++){
			update(t,i,1);
		}
		for (int i=1; i<=m; i++){
			int p;
		 	cin >>p;
			cout <<sum(t,n+m+4)- sum(t,h[p])<<" ";
			update(t,n+i,1);
			update(t,h[p], -1);
			h[p] = n+i;
		}
		cout <<"\n";
	}
	return 0;
}