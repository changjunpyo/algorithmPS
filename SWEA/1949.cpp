#include <iostream>
#include <string.h>
using namespace std;

int N;
int map[8][8]={0,};
int dp[8][8]={-1,};
const int dx[4] ={1,0,-1,0};
const int dy[4] ={0,1,0,-1};
int dfs(int x, int y){
	if (dp[x][y] != -1){
		return dp[x][y];
	}
	dp[x][y] = 1;
	for (int i=0; i<4; i++){
		int new_x = x+dx[i];
		int new_y = y+dy[i];
		if (new_x>=0 && new_x<N && new_y >=0 && new_y<N && map[x][y] > map[new_x][new_y]){
			dp[x][y] = max(dp[x][y],dfs(new_x,new_y)+1);
		}
	}
	return dp[x][y];

}


int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		int K;
		cin >>N >>K;
		int mx =0;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				cin >> map[i][j];
				dp[i][j] = -1;
				mx = max(mx,map[i][j]);
			}
		}
		int ans = 1;
		for (int x=0; x<=K; x++){
			for (int i=0; i<N; i++){
				for (int j=0; j<N; j++){
					map[i][j] -= x;
					for (int a=0; a<N; a++){
						for (int b=0; b<N; b++){
							if (map[a][b] == mx)
								ans = max(ans,dfs(a,b));
						}
					}
					map[i][j] += x;
					memset(dp, -1, sizeof(dp));
				}
			}
		}
		cout <<"#"<<t<<" "<<ans<<"\n";
	}
	return 0;
}