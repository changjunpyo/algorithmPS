#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int st,en;
bool bfs(int weight, vector<bool> &visited, vector<vector<pair<int,int> > > &E){
	for (int i=0; i<visited.size(); i++) visited[i] = false;
	queue<int> q;
	q.push(st);
	visited[st] = true;

	while(!q.empty()){
		int next =q.front();
		q.pop();

		for (auto x: E[next]){
			if (visited[x.first] || weight > x.second ) continue;
			if (x.first == en) return true;
			q.push(x.first);
			visited[x.first] = true;
		}
	}
	return false;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >>N>>M;

	vector<vector<pair<int,int> > > E(N);
	vector<bool> visited(N, false);
	for (int i=0; i<M; i++){
		int x,y,z;
		cin >>x >>y>>z;
		E[x-1].push_back(make_pair(y-1,z));
		E[y-1].push_back(make_pair(x-1,z));
	}
	int a,b;
	cin >> a >>b;
	st = a-1;
	en = b-1;
	int lo = 1;
	int hi = 1000000001;
	while (lo < hi){
		int mid = lo + (hi-lo)/2;

		if (bfs(mid,visited,E )){
			lo= mid+1;
		} else{
			hi = mid;
		}
	}
	cout <<lo-1<<"\n";

	return 0;
}