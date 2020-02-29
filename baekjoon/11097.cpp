#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > scc;
int scc_count =0;
vector<int> edge[301];
stack<int> sta;
int visited[301]={0,};
int out[301]={0,};
int pre[301]={0,};
int finished[301]={0,};
int scc_num[301]={0,};
int scc_edge[301][301]={0,};
bool scc_edge_check[301][301]={false};

vector<pair<int,int> > ans;
int num=0;
int dfs(int u){
	int ret = pre[u] = ++num;
	sta.push(u);
	for (auto v: edge[u]){
		if (pre[v] == 0) ret = min(ret, dfs(v));
		else if (!finished[v]) ret = min(ret, pre[v]);
	}

	if (pre[u] == ret){
		vector<int> component;
		while(1){
			int t = sta.top();
			sta.pop();
			scc_num[t] = scc_count;
			component.push_back(t);
			finished[t] = true;
			if (t == u) break;
		}
		scc_count++;
		scc.push_back(component);
	}

	return ret;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin >>N;
		for (int i=1; i<=N; i++){
			string s;
			cin >>s;
			for (int j=0; j<s.size(); j++){
				if (i==j+1 || s[j] == '0')
					continue;
				edge[i].push_back(j+1);
			}
		}
		// scc
		for (int i=1; i<=N; i++){
			if (pre[i]) continue;
			dfs(i);
		}
		for (int i=1; i<=N; i++){
			for (auto v :edge[i]){
				if (scc_num[i] != scc_num[v]){
						scc_edge[scc_num[i]][scc_num[v]]=1;
						scc_edge_check[scc_num[i]][scc_num[v]]=true;
				}
			}
		}
		for (int i=0; i<scc_count; i++){
			for (int j=0; j<scc_count; j++){
				if (i != j && scc_edge[i][j] ==1){
					for (int k=0; k<scc_count; k++){
						if (k== i || k==j)
							continue;
						if (scc_edge[i][k] && scc_edge[k][j])
							scc_edge_check[i][j]=false;
					}
				}
			}
		}
		for (int i=0; i<scc_count; i++){
			for (int j=0; j<scc_count; j++){
				if (i != j && scc_edge_check[i][j])
					ans.push_back({scc[i][0],scc[j][0]});
			}
		}

		for (int i=scc_count-1; i>=0; i--){
			if (scc[i].size() <2) continue;
			for (int j=0; j<scc[i].size();j++){
				if (j== scc[i].size()-1)
					ans.push_back({scc[i][j],scc[i][0]});
				else
					ans.push_back({scc[i][j], scc[i][j+1]});
			}

		}

		cout << ans.size()<<"\n";

		for (int i=0; i<ans.size(); i++)
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		cout<<"\n";

		memset(pre, 0, sizeof(pre));
		memset(finished, 0, sizeof(finished));
		memset(scc_num, 0, sizeof(scc_num));
		memset(scc_edge, 0, sizeof(scc_edge));
		memset(visited, 0, sizeof(visited));
		memset(scc_edge_check,0, sizeof(scc_edge_check));
		ans.resize(0);
		for (int i=0; i<=N; i++)
			edge[i].resize(0);
		for (int i=0; i<scc_count; i++)
			scc[i].resize(0);
		scc.resize(0);
		scc_count=0;
		num=0;

	}
}