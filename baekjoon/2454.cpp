#include <cstdio>
using namespace std;

vector<int> g[300001];

int main(){
	int N,K;
	scanf("%d %d",&N, &K);
	vector<int> v(N+1);
	
	for (int i=0; i<N-1; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
		v[a]++;
		v[b]++;
	}
	bool check=false;
	for (int i=1; i<N+1; i++){
		if (v[i] > K){
			check=true;
			
		}
	}



}