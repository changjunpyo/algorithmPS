#include <bits/stdc++.h>
using namespace std;
const int MAX =10000;
// 방법1: 코세라주
vector<int> v[MAX];
vector<int> r_v[MAX];
bool visited[MAX]={false,};
stack<int> s;
vector<int> SCC[MAX];
int scc_count;

bool cmp(const vector<int> &x, const vector<int> &y){
	return x[0] < y[0];
}

void dfs(int x){
	visited[x] = true;

	for (auto there: v[x]){
		if (visited[there])
			continue;
		dfs(there);
	}
	s.push(x);
	return;
}

void dfs2(int x){
	visited[x] = true;
	SCC[scc_count].push_back(x);
	for (auto there: r_v[x]){
		if (visited[there])
			continue;
		dfs2(there);
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V,E;

	cin >>V >>E;
	while(E--){
		int x, y;
		cin >>x >>y;
		v[x-1].push_back(y-1);
		r_v[y-1].push_back(x-1);
	}

	for (int i=0; i<V; i++){
		if (visited[i])
			continue;
		dfs(i);
	}

	memset(visited, 0, sizeof(visited));

	while(s.size()){
		int vx = s.top();
		s.pop();
		if (visited[vx])
			continue;
		dfs2(vx);
		scc_count++;
	}

	for (int i=0; i<scc_count; i++)
		sort(SCC[i].begin(),SCC[i].end());
	sort(SCC,SCC+scc_count,cmp);
	cout <<scc_count<<"\n";
	for (int i=0; i<scc_count; i++){
		for (auto x: SCC[i]){
			cout <<x+1<<" ";
		}
		cout <<-1<<"\n";
	}
	return 0;
}