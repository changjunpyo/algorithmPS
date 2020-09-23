#include<iostream>
using namespace std;


int win[6];
int draw[6];
int lose[6];
bool dfs(int x, int y){
	if (x== 6){
		return true;
	}
	if (y == 6) return dfs(x+1, x+2);
	bool ans = false;
	win[x]--, lose[y]--;
	if (win[x] >=0 && lose[y] >= 0) ans |= dfs(x, y+1);
	win[x]++, lose[y]++;

	draw[x]--, draw[y]--;
	if (draw[x] >=0 && draw[y] >=0) ans |= dfs(x, y+1);
	draw[x]++, draw[y]++;

	lose[x]--, win[y]--;
	if (lose[x] >=0 && win[y] >=0) ans |= dfs(x, y+1);
	lose[x]++, win[y]++;

	return ans;
}




int main(){
	for (int k=0; k<4; k++){
		int count =0;
		for (int i=0; i<6; i++){
			cin >>win[i] >> draw[i] >>lose[i];
			count += win[i]+ draw[i]+ lose[i];
		}

		if (count ==30 && dfs(0,1)) cout <<"1 ";	
		else cout <<"0 ";
	}
	cout <<"\n";


}