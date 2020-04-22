#include<iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
const int dx[4] ={1,0,-1,0};
const int dy[4] ={0,1,0,-1};
int map[100][100]={0,};
unordered_map<int,vector<pair<int,int> > > m;
int simulate(int s_x, int s_y,int dir, int N){
	int point =0;
	int x =s_x+ dx[dir], y= s_y+dy[dir];
	while(!(x==s_x && y==s_y)){
		if (x < 0 || y <0 || x>=N || y>=N){
			point++;
			dir = (dir+2)%4;
		}
		else if (map[x][y] == 1){
			point++;
			if (dir == 0){
				dir=1;
			}
			else if (dir ==1){
				dir = (dir+2)%4;
			}
			else if (dir ==2){
				dir = (dir+2)%4;
			}
			else if (dir ==3){
				dir = 2;
			}
		}
		else if (map[x][y] ==2){
			point++;
			if (dir == 0){
				dir = (dir+2)%4;
			}
			else if (dir ==1){
				dir = (dir+2)%4;
			}
			else if (dir ==2){
				dir = 1;
			}
			else if (dir ==3){
				dir = 0;
			}
		}
		else if (map[x][y] ==3){
			point++;
			if (dir == 0){
				dir = (dir+2)%4;
			}
			else if (dir ==1){
				dir =0;
			}
			else if (dir ==2){
				dir =3;
			}
			else if (dir ==3){
				dir = (dir+2)%4;
			}
		}
		else if (map[x][y] ==4){
			point++;
			if (dir == 0){
				dir =3;
			}
			else if (dir ==1){
				dir = 2;
			}
			else if (dir ==2){
				dir = (dir+2)%4;
			}
			else if (dir ==3){
				dir = (dir+2)%4;
			}
		}
		else if (map[x][y] ==5){
			point++;
			dir = (dir+2)%4;
		}
		else if (map[x][y] >5){
			if (make_pair(x,y) == m[map[x][y]][0]){
				auto p = m[map[x][y]][1];
				x = p.first;
				y = p.second;
			}
			else{
				auto p = m[map[x][y]][0];
				x = p.first;
				y = p.second;
			}
			x = x + dx[dir];
			y = y + dy[dir];
			continue;
		}
		else if (map[x][y] == -1)
			break;
		x = x + dx[dir];
		y = y + dy[dir];
	}
	return point;
}

int main(){
	int T;
	cin >>T;

	for (int t=1; t<=T; t++){
		m.clear();
		int N;
		cin >>N;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				cin >>map[i][j];
				if (map[i][j] > 5){
					if (m.find(map[i][j]) != m.end()){
						m[map[i][j]].push_back({i,j});
					}
					else{
						vector<pair<int,int> > v;
						v.push_back(make_pair(i,j));
						m.insert({map[i][j],v});
					}
				}
			}
		}
		int ans =0;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (map[i][j] != 0) continue;
				for (int k=0; k<4; k++){
					ans = max(ans, simulate(i,j,k,N));
				}
			}
		} 
		cout << "#"<<t<<" " <<ans <<"\n";
	}
}