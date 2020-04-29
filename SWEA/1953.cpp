#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
int map[50][50]={0,};
bool check[50][50]={false,};
bool checkConnectivity(int x, int y, int dir){
	if (map[x][y] == 1)
		return true;
	else if (map[x][y]==2){
		if (dir %2 ==0) return true;
		else return false;
	}
	else if (map[x][y]==3){
		if (dir %2 ==1) return true;
		else return false;
	}
	else if (map[x][y]==4){
		if (dir == 1 || dir == 2) return true;
		else return false;
	}
	else if (map[x][y]==5){
		if (dir == 0 || dir ==1) return true;
		else return false;
	}
	else if (map[x][y]==6){
		if (dir == 0 || dir ==3) return true;
		else return false;
	}
	else if (map[x][y]==7){
		if (dir == 2 || dir == 3) return true;
		else return false;
	}
	else 
		return false;
}

int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		int N,M,R,C,L;
		cin >>N>>M>>R>>C>>L;
		for (int i=0; i<N; i++){
			for (int j=0; j<M; j++){
				cin >>map[i][j];
				check[i][j] = false;
			}
		}
		int count =1;
		queue<pair<int,int> > q;
		q.push(make_pair(R,C));
		check[R][C]= true;
		for (int i=1; i<L; i++){
			int s = q.size();
			for (int x=0; x<s; x++){
				auto p = q.front();
				q.pop();
				for (int dir=0; dir<4; dir++){
					if (map[p.first][p.second] ==2 && dir %2 == 1) continue;
					else if (map[p.first][p.second] ==3 && dir %2 == 0) continue;
					else if (map[p.first][p.second] ==4 && (dir == 0 || dir == 3)) continue;
					else if (map[p.first][p.second] ==5 &&(dir == 2 || dir == 3) ) continue;
					else if (map[p.first][p.second] ==6 &&(dir == 1 || dir == 2) ) continue;
					else if (map[p.first][p.second] ==7 && (dir == 0 || dir == 1) ) continue;
					int new_x = p.first+ dx[dir];
					int new_y = p.second+ dy[dir];
					if (new_x<0 || new_y<0 || new_x>=N || new_y>=M || map[new_x][new_y] == 0|| check[new_x][new_y]) continue;
					if (checkConnectivity(new_x,new_y,(dir+2)%4)){
						check[new_x][new_y] = true;
						q.push(make_pair(new_x,new_y));
						count++;
					}
				}
			}
		}


		cout <<"#"<<t<<" "<<count<<"\n";
	}
	return 0;
}