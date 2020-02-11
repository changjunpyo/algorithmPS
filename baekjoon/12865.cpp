#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N,K;
	int V[101];
	int W[101];
	int dp[2][100001]={0,};
	scanf("%d %d",&N,&K);
	for (int i=1; i<N+1; i++){
		scanf("%d %d",&W[i],&V[i]);
	}


	for (int i=1; i<N+1; i++){
		for (int j=0; j<K+1; j++){
			if (j- W[i] >=0){
				dp[1][j] = max(dp[0][j],V[i]+ dp[0][j-W[i]]);
			}
		}
		for (int j=0; j<K+1; j++){
			dp[0][j] = dp[1][j];
		}
	}

	printf("%d\n",dp[0][K]);
}