#include <iostream>
#include <vector>
using namespace std;

int board[20][20]={0,};

int ans;
int N;

bool visit(int a_count,int b_count, int s_x, int s_y){
	bool cafe[101]={false,};
	int x = s_x;
	int y = s_y;
	for(int i=0; i<a_count; i++){
		x++;
		y++;
		if (cafe[board[x][y]]) return false; 
		cafe[board[x][y]]= true;
	}
	for (int j=0; j<b_count; j++){
		x++;
		y--;
		if (cafe[board[x][y]]) return false; 
		cafe[board[x][y]]= true;
	}
	for(int i=0; i<a_count; i++){
		x--;
		y--;
		if (x <0 || y< 0) return false;
		if (cafe[board[x][y]]) return false;
		cafe[board[x][y]]= true;
	}
	for (int j=0; j<b_count; j++){
		x--;
		y++;
		if (x <0 || y >= N) return false;
		if (cafe[board[x][y]]) return false;
		cafe[board[x][y]]= true;
	}
	if (x == s_x && y == s_y) return true;
	else return false; 
}


int dfs(int s_x, int s_y){
	int count =0;
	for (int i=1; i<N; i++){
		int x = s_x + i;
		int y = s_y + i;
		if (x >=N || y>= N) break;
		for (int j=1; j<N; j++){
			int new_x = x +j;
			int new_y = y -j;
			if (new_x >=N || new_y < 0) break;
			if (visit(i,j, s_x,s_y)){ 
				count = max(count, 2*i+ 2*j);
			}
		}
	}
	return count;
}



int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		cin >>N;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				cin >>board[i][j];
			}
		}
		int ans =0;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				ans = max(ans,dfs(i,j));
			}
		}
		if (ans ==0) ans = -1;
		cout <<"#"<<t<<" "<<ans<<"\n";
	}
}