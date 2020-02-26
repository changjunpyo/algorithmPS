#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
vector<int> edge[20001];
vector<int> st;
int num=0;
int pre[20001]={0,};
int finished[20001] ={0,};
int ans=0;
int dfs(int u){
	int ret = pre[u] = ++num;
	st.push_back(u);
	for (auto v: edge[u]){
		if (pre[v] == 0) ret = min(ret, dfs(v));

		else if (!finished[v]) ret = min(ret, pre[v]);
	}

	if (ret == pre[u]){

		while(1){
			int t = st.back();
			st.pop_back();
			finished[t] =1;
			if (t==u) break;
		}
		ans++;
	}
	return ret;
}


int main(){
	fastio
	int t;
	cin >>t;
	while(t--){
		int v,e;
		cin >>v>>e;
		while (e--){
			int x,y;
			cin >>x >>y;
			edge[x].push_back(y);
		}

		for (int i=1; i<=v; i++){
			if (pre[v]) continue;
			dfs(i);
		}
		cout <<ans<<"\n";
		// reset

		for (int i=1; i<=v; i++)
			edge[i].resize(0);
		ans =0;
		st.resize(0);
		memset(pre,0, sizeof(pre));
		memset(finished,0, sizeof(finished));
		num=0;
	}
}