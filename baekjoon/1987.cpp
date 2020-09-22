#include <iostream>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
bool alph[26] ={false};
int map[21][21] = {};
int R, C;

int dfs(int x, int y, int count){
	if (count == 26) return 26;
	alph[map[x][y]] = true;
	int ret =count;
	for (int i=0; i<4; i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_x>=0 && new_x< R && new_y>=0 && new_y<C
		 && !alph[map[new_x][new_y]]){
			ret =max(ret, dfs(new_x,new_y, count+1));
			if (ret == 26) return 26;
		}
	}
	alph[map[x][y]] = false;
	return ret;
}


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >>R>>C;
	for (int i=0; i<R; i++){
		for (int j=0; j<C; j++){
			char c;
			cin >> c;
			map[i][j] = c- 'A';
		}
	}
	cout <<dfs(0,0,1)<<"\n";
	return 0 ;
}