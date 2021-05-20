#include <iostream>
#include <vector>
using namespace std;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int mx_core=0;
int mn_wire = 987654321;
int N;
int M;
int core_size;
int map[12][12];
vector<pair<int,int> > p;
bool check(int x, int y, int dir){
	for (int i=0; i<M; i++){
		x = dx[dir]+x;
		y = dy[dir]+y;
		if (x < 0 || x>=M || y<0 || y >= M) return true;
		if (map[x][y] >= 1) return false;
	}
	return false;
}
int make_wire(int x, int y, int dir){
	int count =0;
	for (int i=0; i<M; i++){
		x = dx[dir]+x;
		y = dy[dir]+y;
		if (x < 0 || x>=M || y<0 || y >= M) return count;
		map[x][y] = 2;
		count++;
	}
	return count;
}
void remove_wire(int x, int y, int dir){
	for (int i=0; i<M; i++){
		x = dx[dir]+x;
		y = dy[dir]+y;
		if (x < 0 || x>=M || y<0 || y >= M) return;
		map[x][y] = 0;
	}
}
void dfs(int wire, int core, int idx){
	if (idx >= core_size || mx_core > core+ (core_size-idx)) return;

	auto pos = p[idx];
	for (int k=0; k<4; k++){
		if (check(pos.first, pos.second, k)){
			int cnt = make_wire(pos.first, pos.second, k);
			if (core+1>= mx_core){
				if (core+1 > mx_core){
					mn_wire = wire+cnt;
				} else if (core +1 == mx_core){
					if (mn_wire > cnt+wire){
						mn_wire= cnt+wire;
					}
				}
				mx_core = core+1;
			}
			dfs(wire+cnt, core+1, idx+1);
			remove_wire(pos.first, pos.second, k);
		} 
	}
	dfs(wire, core, idx+1);
}


int main(){
	
	cin >>N;
	for (int t=0; t<N; t++){
		cin >>M;
		for (int i=0; i<M; i++){
			for (int j=0; j<M; j++){
				cin >> map[i][j];
				if (map[i][j] == 1)
					p.push_back(make_pair(i,j));
			}
		}
		core_size = p.size();
		dfs(0,0,0);
		cout <<"#" <<t+1 <<" "<<mn_wire<<"\n";
		p.resize(0);
		mx_core = 0;
		mn_wire = 987654321;
	}
}
