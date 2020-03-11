#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int A[101];
int B[101];
bool visited[101]={false,};
bool dfs(int u){
	visited[u] = true;

	for (auto v: adj[u]){
		if (B[v]== -1 || (!visited[B[v]] && dfs(B[v])) ) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >>N >>M; 

	for(int i=0; i<M; i++){
		int u,v;
		cin >>u >>v;
		adj[u].push_back(v);
	}
	int ans =0;
	memset(A,-1 , sizeof(A));
	memset(B,-1, sizeof(B));


	for (int i=1; i<=N; i++){
		memset(visited,false, sizeof(visited));

		if (dfs(i)) ans++;
	}

	cout <<ans <<"\n";

}