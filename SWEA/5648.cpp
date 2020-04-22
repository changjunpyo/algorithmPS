#include<iostream>
#include <vector>
#include <cmath>
#include <list>
#include <unordered_map>
using namespace std;
const int dx[4] ={-1,1,0,0};
const int dy[4] ={0,0,-1,1};

int map[2000][2000]={0,};
int main(){
	int T;
	cin >>T;
	//(x,y,dir,b)
	list<vector<int>> l;
	for (int t=1; t<=T; t++){
		int N;
		cin >>N;
		for (int i=0; i<N; i++){
				int x,y,dir,b;
				cin >> x >>y >>dir >>b;
				vector<int> v={x+1000,y+1000, dir, b,0};
				l.push_back(v);
				map[x+1000][y+1000]= dir
		}
		while(l.size() != 0){
			memset(check,0, sizeof(check));
			memset(copy_map, -1, sizeof(copy_map));
			for (auto c : l){
				int x = c[0]+ dx[c[2]];
				int y = c[1]+ dy[c[2]];
				if (x <0 || x >= N || y <0 || y >= 0){
					c[4] =1;
				}
				if (x >=0 && x <N && y >=0 && y<N && map[x][y] > 0 && (map[x][y] + c[2]) %4 == 1){
						c[4] = 1;
						ans+= c[3];
				}
				if (c[4]) continue;
				copy_map[x][y] = c[2];
				check[x][y]++;
			}
			for (auto c : l){
				if (c[4] == 1) {
					l.erase(c)
					continue;
				};

			}
		}
		cout << "#"<<t<<" " <<ans <<"\n";
	}
}