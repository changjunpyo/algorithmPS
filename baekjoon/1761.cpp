#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 40001;
int par[MAX_SIZE][20]={0,};
int d[MAX_SIZE]={0,};
int di_root[MAX_SIZE]={0,};
bool visited[MAX_SIZE]={false,};
vector<pair<int,int> > v[MAX_SIZE];

void dfs(int depth, int x, int dir){
	visited[x] = true;
	d[x] = depth;
	di_root[x] = dir;
	for (auto a: v[x]){
		if (visited[a.first])
			continue;
		par[a.first][0] = x;
		dfs(depth+1, a.first, dir+a.second);
	}
}

void make_parent(int N){
	for (int i=1; i<20; i++){
		for (int j=1; j<=N; j++){
			par[j][i] = par[par[j][i-1]][i-1];
		}
	}
}
// x 
int lca(int x, int y){
	if (d[x] > d[y]){
		int t = x;
		x = y;
		y = t;
	}

	for (int i=19; i>=0; i--){
		if (d[y] - d[x] >= (1<< i) )
			y = par[y][i];
	}

	if (x == y)
		return x;


	for (int i=19; i>=0; i--){
			if (par[x][i] != par[y][i]){
				x = par[x][i];
				y = par[y][i];
			}
	}
	return par[x][0];



}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >>N;

	for (int i=0; i<N-1; i++){
		int a,b,c;
		cin >> a >>b >>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}

	dfs(0,1,0);
	make_parent(N);
	cin >>M;
	for(int i=0; i<M; i++){
		int x,y;
		cin >>x >>y;
		int z = lca(x,y);
		int ans = di_root[x] + di_root[y] - 2*di_root[z];
		cout <<ans <<"\n";
	}


}