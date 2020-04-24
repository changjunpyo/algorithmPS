#include <iostream>
#include <vector>
using namespace std;

bool board[13][20]={false};
bool visited[13]={false};
int ans;
bool checkPass(int K, int D, int W){
	bool flag = true;

	for (int i=0; i<W; i++){
		int count = 1;
		int mx_count =1;
		for (int j=0; j<D-1; j++){
			if (D- j < K && mx_count ==1) return false; 
			if (mx_count >= K) break;
			if (board[j][i] == board[j+1][i]) {
				count++;
				mx_count = max(mx_count,count);
			}
			else{
				count =1;
			}
		}
		if (mx_count <K) return false;;

	}
	return flag;
}
void changeRow(int row, bool A,int W){
	for (int i=0; i<W; i++){
		board[row][i] = A;
	}
}


int brute_force(int K, int count, int prev, int D,int W){
	if (count >= ans) return ans;
	if (count >= K || checkPass(K, D,W)) return count;
	for (int i=prev+1; i<D; i++){
		if (visited[i]) continue;
		bool map[20] ={false,};
		for (int j=0; j<W; j++){
			map[j] = board[i][j];
		}
		visited[i] = true;
		changeRow(i,true,W);
		ans = min(ans,brute_force(K, count+1,i,D,W));
		changeRow(i,false,W);
		ans = min(ans,brute_force(K, count+1,i,D,W));
		for (int j=0; j<W; j++){
			board[i][j] = map[j];
		}
		visited[i] =false;
	}
	return ans;
}

int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		int D,W,K;
		cin >>D >>W>>K;
		ans = K;
		for (int i=0; i<D; i++){
			for (int j=0; j<W; j++){
				int x;
				cin >>x;
				board[i][j] = x;
			}
		}

		if (K==1) 
			ans =0;
		else
			ans = brute_force(K,0,-1,D,W);
		cout <<"#"<<t<<" "<<ans<<"\n";
	}
}