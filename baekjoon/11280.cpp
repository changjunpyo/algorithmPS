#include <bits/stdc++.h>
using namespace std;

int pre[20001]={0,};
int finished[20001]={0,};
vector<int> edge[20001];
int num=0;
int scc_num[20001]={0,};
int scc_count = 0;
stack<int> sta;
int oppo(int x){
	return x%2 ?x-1: x+1; 
}

int dfs(int u){
	int ret = pre[u] = ++num;
	sta.push(u);
	for (auto v: edge[u]){
		if (pre[v]==0) ret = min(ret, dfs(v));
		else if (!finished[v]) ret = min(ret,pre[v]);
	}
	if (pre[u]== ret){
		while(1){
			int t = sta.top();
			sta.pop();
			finished[t] = 1;
			scc_num[t] = scc_count;
			if (t == u) break;
		}
		scc_count++;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >>N >>M;

	for (int i=0; i<M; i++){
		int x,y;
		cin>> x >>y;
		x = (x <0)? -(x+1)*2 : 2*x-1;
		y = (y <0)? -(y+1)*2 : 2*y-1;

		edge[oppo(x)].push_back(y);
		edge[oppo(y)].push_back(x);
	}

	for (int i=0; i<N*2; i++){
		if (pre[i]) continue;
		dfs(i);
	}

	for (int i=0; i<N; i++){
		if (scc_num[i*2] == scc_num[2*i+1]){
			cout <<0<<"\n";
			return 0;
		}
	}
	cout <<1<<"\n";




}