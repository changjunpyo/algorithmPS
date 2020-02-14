#include <iostream>
#include <vector>
using namespace std;
int par[50001][20]={0,};
int d[50001]={0,};
bool visited[50001]={false,};
vector<int> v[50001];

void dfs(int depth, int x){
	visited[x] = true;
	d[x] = depth;
	for (auto a: v[x]){
		if (visited[a])
			continue;
		par[a][0] = x;
		dfs(depth+1, a);
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
		int a,b;
		cin >> a >>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(0,1);
	make_parent(N);
	cin >>M;
	for(int i=0; i<M; i++){
		int a,b;
		cin >>a >>b;
		cout << lca(a,b) <<"\n";
	}




}