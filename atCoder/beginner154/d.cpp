#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N,K;
	double arr[200000];
	double ans=0;
	scanf("%d %d",&N,&K);
	for (int i=0; i<N; i++){
		double num;
		scanf("%lf",&num);
		arr[i] = (1.0+num)/2;
	}
	double ret =0;
	for (int i=0; i<K; i++){
		ret+= arr[i];
	}
	ans = max(ans,ret);
	for (int i=K; i<N; i++){
		ret += (arr[i] - arr[i-K]);
		ans = max(ans,ret);
	}

	printf("%lf\n",ans);

}