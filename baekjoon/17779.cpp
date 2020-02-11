#include <cstdio>
#include <stdio.h>
using namespace std;
int map[20][20];
int dist[5]={0,};

int cal_district(int x,int y, int d1, int d2,int N){
	

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (x<= i && i <= x+d1+d2  && y-d1<=j && y+d2 >=j && i+j >= x+y && (i-j >= x-y )&& i+j <= x+y+2*d2 && i-j <= x-y+2*d1)
				dist[4]+= map[i][j];
			else if (i >=0 && i<x+d1 && j>=0 && j<=y){
				dist[0]+= map[i][j];
			}
			else if (i >=0 && i<=x+d2 && j> y && j <N){
				dist[1]+= map[i][j];
			}
			else if (i >=x+d1 && i<N && j>=0 && j<y-d1+d2){
				dist[2]+= map[i][j];
			}
			else if (i >x+d2 && i<N && j>= y-d1+d2 && j<N){
				dist[3]+= map[i][j];
			}
		}
	}

	int mn = 100000000;
	int mx = -1;

	for (int i=0; i<5; i++){
		if (dist[i] > mx )
			mx = dist[i];
		if (dist[i] < mn)
			mn = dist[i];
		dist[i] = 0;
	}
	return mx - mn;
}

int main(){
	int N;
	scanf("%d",&N);

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d",&map[i][j]);
		}
	}
	int mn = 987654321;
	for (int x=0; x<N; x++){
		for (int y=0; y<N; y++){
			for (int d1=1; d1<N; d1++){
				for (int d2=1; d2<N; d2++){
					if (x+d1+d2< N && y-d1 >=0 && y+d2 <N){
						int t = cal_district(x,y,d1,d2,N);
						if (mn > t)
							mn = t;
						if (x==2 && y==2 && d1==1 &d2==1)
							printf("asdasd: %d\n", t);
					}
				}
			}
		}
	}

	printf("%d\n",mn );

}