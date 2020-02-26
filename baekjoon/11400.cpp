#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
const int MAX_VERTEX = 100001;
vector<int> edge[MAX_VERTEX];
vector<pair<int,int> > seperate_edge;
int pre[MAX_VERTEX]={0,};
int num=0;

int dfs(int u, int par){
	int ret = pre[u] = ++num;
	
	for (auto v: edge[u]){
		if (v== par) continue;

		if (pre[v]) ret = min(ret, pre[v]);
		
		else{
			int temp = dfs(v, u);
			ret = min(temp, ret);

			if (temp > pre[u]){
				if (u > v)
					seperate_edge.push_back({v,u});
				else
					seperate_edge.push_back({u,v});
			}
		}

	}

	return ret;
}


int main(){
	fastio
	int V,E;
	cin >>V >>E;

	while(E--){
		int x,y;
		cin >>x >>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	for (int i=1; i<=V; i++){
		if (pre[i]) continue;
		dfs(i,-1);
	}
	sort(seperate_edge.begin(),seperate_edge.end());
	cout << seperate_edge.size()<<"\n";

	for (auto x: seperate_edge)
		cout <<x.first<< " " <<x.second<<"\n";

}