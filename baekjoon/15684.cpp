#include <iostream>
using namespace std;

bool ladder[31][11]={false,};
int ret= 4;
bool start_game(int N, int H){
	int count =0;
	for (int i=1; i<=N; i++){
		int pos = i;
		for (int j=1; j<=H; j++){
			if (ladder[j][pos]){
				pos = pos+1;
			}
			else if (ladder[j][pos-1]){
				pos = pos-1;
			}

		}
		if (pos != i) return false;
	}
	return true;
}

void add_ladder(int N, int H , int count, int total, int x, int y){
	if (ret != 4) return;
	if (count == total){
		if (start_game(N,H)) {
			ret = count;
		}
		return;
	}
	bool ans = false;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=H; j++){
			if (ladder[j][i] || ladder[j][i-1] || ladder[j][i+1]) continue;
			ladder[j][i] = true;
			add_ladder(N,H, count+1, total, x,y+1);
			ladder[j][i] = false;
			while(!ladder[j][i - 1] && !ladder[j][i + 1]) j++;
 		}
		y= 0;
	}
}

int main(){

	int N, M, H;

	cin >>N >>M >>H;

	for (int i=0; i<M; i++){
		int a, b;
		cin >>a >>b;
		ladder[a][b]= true;
	}

	for (int i=0; i<=3; i++){
		add_ladder(N,H, 0,i, 1,1);
		if (ret != 4){
			cout<<ret <<"\n";
			return 0;
		}
	}
	cout <<"-1"<<"\n";
	return 0;

}