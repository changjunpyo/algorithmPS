#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
const int MAX_VERTEX = 10001;
vector<int> edge[MAX_VERTEX];
vector<int> seperate_point;
//vector<pair<int,int>> seperate_edge;
int pre[MAX_VERTEX]={0,};

int num=0;
int dfs(int u, int par){
	// cnt: 자기 자식의 개수, flag: 단절점인지 아닌지
	// root노드 에서는 cnt >=2 이면 단절점
	// root노드가 아니면
	int cnt=0,flag =0;
	int ret = pre[u] = ++num;

	for (auto v: edge[u]){
		// 자기 부모로 가려는 edge일때
		if (v == par)
			continue;
		// 방문한 간선이면 (역방향 간선이면)
		if (pre[v]>0) ret = min(ret, prev[v]);
		// 방문하지 않은 간선이면
		if (!pre[v]){
			int temp = dfs(v, u);
			ret = min(ret,temp);
			cnt++;
			// v에서 dfs로 도달할수 있는 것 중 최소가 u보다 크거나 같으면 bcc
			if (temp >= pre[u]){
				flag = 1;
			}
		}
	}

	if (cnt>=2 && par == -1) seperate_point.push_back(u);
	else if (flag && par != -1) seperate_point.push_back(u);

	// 자기가 도달할수 있는 node의 최솟값
	return ret;

}

int main(){
	fastio
	int V,E;
	cin >>V >>E;
	for (int i=0; i<E; i++){
		int x,y;
		cin >>x >>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for (int i=1; i<=V; i++){
		if (pre[i]>0) continue;
		dfs(i,-1);
	}

	cout <<seperate_point.size();
	for (auto x: seperate_point)
		cout <<x<<" ";
	cout <<"\n";
	return 0;
}