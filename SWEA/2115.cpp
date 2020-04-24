#include <iostream>
#include <vector>
using namespace std;


int N,C,M;
int board[10][10];

int all_case(int sum, int price, int x,int y, int prev){
	if (prev == y+M-1){
		return price;
	}
	int ret = price;
	for (int i=prev+1; i<y+M; i++){
		if (sum+board[x][i]> C) continue;
		sum += board[x][i];
		price += board[x][i]*board[x][i];
		ret = max(ret,all_case(sum,price,x, y, i));
		sum -= board[x][i];
		price -= board[x][i]*board[x][i];
	}
	return ret;
}


int choose(int x, int y){
	return all_case(0,0, x, y, y-1);
}
int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		cin >>N >>M>>C;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				cin >>board[i][j];
			}
		}
		int ans = 0;
		for (int i=0; i<N; i++){
			for (int j=0; j<=N-M; j++){
				int x =choose(i,j);
				for (int k=i; k<N; k++){
					for (int r=0; r<=N-M; r++){
						if (k==i && r<j+M) continue;
						int y = choose(k,r);
						ans = max(ans,x+y);
					}
				}
			}
		}
		cout <<"#"<<t<<" "<<ans<<"\n";
	}
}