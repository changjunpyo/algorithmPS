#include <cstdio>
using namespace std;
#define MAX_DIS 123456789
int dis[501][501]={0,};

int main(){
	int N,M,ans=0;
	scanf("%d %d",&N,&M);
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++)
			dis[i][j]= MAX_DIS;
	}
	for(int i=0; i<M; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		dis[a][b] = 1;
	}
	for (int k=1; k<=N; k++){
		for (int i=1; i<=N; i++){
			for (int j=1; j<=N; j++){
					if (dis[i][k] + dis[k][j] < dis[i][j])
						dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}

	for (int i=1; i<=N; i++){
		int count= 0;
		for (int j=1; j<=N; j++){
			if (i==j)
				continue;
			if (dis[i][j] == MAX_DIS && dis[j][i] == MAX_DIS){
				count=1;
				break;
			}
		}
		if (count==0)
			ans++;
	}
	
	printf("%d\n",ans );
}