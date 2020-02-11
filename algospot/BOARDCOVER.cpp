#include <iostream>
using namespace std;

const int coverType[4][3][2]={
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {0,1}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};
int map[20][20];

int set(int y, int x,int H, int W, int type, int delta){
	bool check=true;

	for (int i=0; i<3; i++){
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny <0 || ny >= H || nx <0 || nx >= W)
			check = false;
		else if ((map[ny][nx] += delta) > 1)
			check = false;
	}

	return check;
}

int coverMap(int H, int W){
	int x = -1, y=-1;
	for (int i=0; i<H; i++){
		for (int j=0; j<W; j++)
			if (map[i][j] == 0){
				y=i;
				x=j;
				break;
			}
		if (y!=-1)
			break;
	}
	//base case
	if (y == -1) return 1;

	int ret=0;
	for (int t=0; t<4; t++){
		if (set(y,x,H,W,t,1))
			ret += coverMap(H,W);
		set(y,x,H,W,t,-1);
	}

	return ret;
}
int main(){
	int T;
	cin >> T;
	for (int t=0; t<T; t++){
		int H,W;
		char c;
		cin >>H >>W;
		for (int i=0; i<H; i++){
			for (int j=0; j<W; j++){
				cin >> c;
				if (c == '#')
					map[i][j] = 1;
				else
					map[i][j] = 0;
			}
		}
		printf("%d\n",coverMap(H,W));
	}
	return 0;
}