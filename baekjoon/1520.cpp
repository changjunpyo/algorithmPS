#include <cstdio>
using namespace std;

int map[500][500];
int dp[500][500];
int dfs(int i,int j, int M, int N){
	if (i== M-1 && j== N-1)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans =0;
	if (i >0 && map[i-1][j] < map[i][j]){
		ans += dfs(i-1,j,M,N);
	}
	if (i<M-1 && map[i+1][j] < map[i][j]){
		ans += dfs(i+1,j,M,N);
	}
	if (j >0 && map[i][j-1] < map[i][j]){
		ans += dfs(i,j-1,M,N);
	}
	if (j<N-1 && map[i][j+1] < map[i][j]){
		ans += dfs(i,j+1,M,N);
	}
	dp[i][j] = ans;
	return dp[i][j];
}


int main(){
	int M,N;
	scanf("%d %d",&M,&N);

	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			scanf("%d",&map[i][j]);
			dp[i][j] =-1;
		}
	}
	printf("%d\n",dfs(0,0,M,N) );

}