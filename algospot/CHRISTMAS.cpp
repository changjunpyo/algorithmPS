#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 20091101;

int psum[100001];
int cache[100001];
int pre[100001];
long long int way_to_give(int K,int N){
	long long int ans=0;
	vector<long long int> v(K,0);

	for (int i=0; i<N+1; i++){
		v[psum[i]]++;
	}

	for (int i=0; i<K; i++){
		if (v[i] == 0 || v[i] == 1)
			continue;
		ans = (((v[i]*(v[i]-1))/2)+ ans) %MOD;
	}

	return ans;
}
// k번 까지 상자를 범위로 겹치치 않게 최대로 주문횟수를 리턴 값으로 받음
// 
int max_order(int k){
	int &ret = cache[k];
	if (ret != -1)
		return ret;
	
	ret =0;
	if (k>0)
		ret = max(max_order(k-1), ret);

	if (pre[psum[k]] != -1)
		ret = max(max_order(pre[psum[k]])+1, ret);
	
	pre[psum[k]] = k;
	return ret;
}


int main(){
	int C;

	scanf("%d",&C);

	while(C--){

		int N,K;
		scanf("%d %d",&N,&K);
		memset(psum, 0, sizeof(psum));
		memset(cache, -1, sizeof(cache));
		memset(pre, -1, sizeof(pre));
		for (int i=1; i<=N; i++){
			int num;
			scanf("%d",&num);
			psum[i] = (psum[i-1] + num) %K;
		}

		printf("%lld %d\n",way_to_give(K,N), max_order(N));


	}

}