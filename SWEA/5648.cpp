#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dx[4] ={0,0,-1,1};
const int dy[4] ={1,-1,0,0};

 class atom{
 public:
 	atom(int _x,int _y, int _dir, int _e){
 		x = _x;
 		y = _y;
 		dir = _dir;
 		e = _e;
 		explode = false;
 	}
 	int x,y;
 	int dir;
 	int e;
 	bool explode;
 };

int map[4001][4001];

int main(){
	int N,K;
	cin >>N;
	for (int t=0; t<N; t++){
		cin >>K;
		int count = 0;
		memset(map, 0, sizeof(map));
		vector<atom> v(K, atom(0,0,0,0));
		for (int i=0; i<K; i++){
			int x,y,dir,e;
			cin >>x >>y >>dir >> e;
			atom a = atom(2*(x+1000),2*(y+1000),dir,e);
			v[i] = a;
			
		}
		int ans =0;
		while(count <=4000){
			bool check = false;
			for (int i=0; i<K; i++){
				if (v[i].explode) continue;
				check = true;
				int x = v[i].x;
				int y = v[i].y;
				v[i].x += dx[v[i].dir];
				v[i].y += dy[v[i].dir];
				map[x][y] = 0;
				if (v[i].x <0 || v[i].x > 4000 || v[i].y <0 || v[i].y >4000) {
					v[i].explode = true;
					continue;
				}
				if (map[v[i].x][v[i].y] == 1){
					map[v[i].x][v[i].y]+=2;
				} else{
					map[v[i].x][v[i].y]++;
				}
			}
			if (!check) break;
			for (int i=0; i<K; i++){
				if (v[i].explode) continue;
				if (map[v[i].x][v[i].y] == 1) continue;
				if (map[v[i].x][v[i].y] == 2 ){
					map[v[i].x][v[i].y]--;
				}
				map[v[i].x][v[i].y]--;
				ans += v[i].e;
				v[i].explode = true;
			}
			count++;
		}
		cout <<"#" <<t+1 <<" "<<ans<<"\n";
	}
}