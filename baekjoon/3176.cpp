#include <bits/stdc++.h>
using namespace std;
# define fastio ios::sync_with_stdio(false); cin.tie(NULL);
bool visited[100001]={false};
int par[100001][18];
int mx[100001][18];
int mn[100001][18];
int d[100001]={0,};
void dfs(int idx, int val, vector<vector<pair<int,int> > > & v){
	visited[idx] = true;
	d[idx] = val;
	for (auto here: v[idx]){
		if (visited[here.first])
			continue;
		par[here.first][0] = idx;
		mx[here.first][0] = here.second;
		mn[here.first][0] = here.second;
		dfs(here.first, val+1, v);
	}


}

void make_parent(int N){
	for (int i=1; i<17; i++){
		for (int j=1; j<=N; j++){
			par[j][i] = par[par[j][i-1]][i-1];
			mx[j][i] = max(mx[j][i-1], mx[par[j][i-1]][i-1]);
			mn[j][i] = min(mn[j][i-1], mn[par[j][i-1]][i-1]);
		}
	}
}

int lca(int x, int y){
	if (d[x] > d[y]){
		int t = x;
		x = y;
		y = t;
	}

	for (int i=17; i>=0; i--){
		if (d[y] - d[x] >= (1<< i) )
			y = par[y][i];
	}

	if (x == y)
		return x;


	for (int i=17; i>=0; i--){
			if (par[x][i] != par[y][i]){
				x = par[x][i];
				y = par[y][i];
			}
	}
	return par[x][0];
}

pair<int,int> find_mn_mx(int x, int y){
	int mn2 =987654321;
	int mx2 =-987654321;
	for (int i=17; i>=0; i--){
		if (d[y] - d[x] >= (1<< i) ){
			mn2 = min(mn[y][i],mn2);
			mx2 = max(mx[y][i],mx2);
			y = par[y][i];
		}
	}
	return make_pair(mn2,mx2);
}


int main(){
	fastio;
	int N,K;
	cin >>N;
	vector<vector<pair<int,int> > > v(N+1);
	for (int i=0; i<N-1; i++){
		int a,b,c;
		cin >>a >>b >>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	dfs(1,0,v);
	make_parent(N);

	cin >> K;
	while(K--){
		int x,y;
		cin >> x>>y;
		int z = lca(x,y);
		pair<int,int> p1 = find_mn_mx(z,x);
		pair<int,int> p2 = find_mn_mx(z,y);
		cout << min(p1.first,p2.first) <<" "<< max(p1.second,p2.second)<<"\n";
	}
	return 0;
}