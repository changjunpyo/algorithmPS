#include <bits/stdc++.h>
using namespace std;

void update(vector<pair<long long,int> > &tree, long long  i, int diff){
	while(i <tree.size()){
		tree[i].first += diff;
		tree[i].second += 1;
		i += (i &-i);
	}
}

pair<long long,int> sum(vector<pair<long long,int> > &tree , int i){
	long long ans = 0;
	int ans2 =0;
	while(i >0){
		ans += tree[i].first;
		ans2 += tree[i].second;
		i -= (i& -i);
	}
	return make_pair(ans,ans2);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >>n;
	vector<pair<long long,int> > t(200002,make_pair(0,0));
	long long int ans =1;
	for (int i=1; i<=n; i++){
		long long num;
		long long  ret=0;
		cin >>num;
		pair<long long ,int> sum_t= sum(t,200001);
		pair<long long ,int> sum_t_num = sum(t,num+1);
		pair<long long ,int> sum_t_num2 = sum(t,num);
		ret += (sum_t.first - sum_t_num.first) - (num* (sum_t.second - sum_t_num.second));
		ret += (num*(sum_t_num2.second) - (sum_t_num2.first)); 
		update(t,num+1,num);
		if (i !=1)
			ans = (ans * (ret%1000000007)) %1000000007;
	}

	cout <<ans<<"\n";

	

	return 0;
}