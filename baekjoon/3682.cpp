#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
vector<int> edge[20001];
vector<int> scc_edge[20001];
stack<int> st;
int num=0;
int pre[20001]={0,};
int scc_num[20001]={0,};
int finished[20001] ={0,};
int in[20001]={0,};
int out[20001]={0,};
int scc_count=0;
int ans1=0;
int ans2=0;
int dfs(int u){
	int ret = pre[u] = ++num;
	st.push(u);
	for (auto v: edge[u]){
		if (pre[v] == 0) ret = min(ret, dfs(v));

		else if (!finished[v]) ret = min(ret, pre[v]);
	}

	if (ret == pre[u]){
		while(1){
			int t = st.top();
			scc_num[t] = scc_count;
			finished[t] =1;
			st.pop();
			if (t==u) break;
		}
		scc_count++;
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
			if (pre[i]>0) continue;
			dfs(i);
		}
		
		for (int i=1; i<=v; i++){
			for (int j: edge[i]){
				if (scc_num[i] != scc_num[j])
					scc_edge[scc_num[i]].push_back(scc_num[j]);
			}
		}

		for (int i=0; i<scc_count; i++){
			for (int j: scc_edge[i]){
				out[i] += 1;
				in[j] += 1;
			}
		}

		for (int i=0; i<scc_count; i++){
			ans1 += !in[i];
			ans2 += !out[i];
		}
		if (scc_count == 1)
			cout <<0<<"\n";
		else
			cout <<max(ans1,ans2)<<"\n";
		// reset
		for (int i=1; i<=v; i++){
			edge[i].resize(0);
			scc_edge[i].resize(0);
		}
		scc_count =0;
		ans1=0;
		ans2=0;
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(scc_num,0,sizeof(scc_num));
		memset(pre,0, sizeof(pre));
		memset(finished,0, sizeof(finished));
		num=0;
	}
}