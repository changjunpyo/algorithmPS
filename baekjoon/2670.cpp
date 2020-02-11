#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N;
	double arr[10000];
	double dp[10000];
	scanf("%d",&N);
	for (int i=0; i<N; i++){
		scanf("%lf",&arr[i]);
		dp[i] = arr[i];
	}
	double mx = arr[0];
	for (int i=1; i<N; i++){
		dp[i] = max(dp[i],dp[i]*dp[i-1]);
		mx = max(mx, dp[i]);
	}
	printf("%.3lf\n", mx);
}