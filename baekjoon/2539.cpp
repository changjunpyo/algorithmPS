#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int binary_search(int num, const vector<pair<int,int> > &v){
	int s=0;
	int e = v.size();
	int m = (s+e)/2;

	while(s+1 < e){
		if (num > v[m].first)
			s = m;
		else if (num <= v[m].first)
			e = m; 
		m = (s+e)/2;
	}

	return e;

}


int main(){
	int N,S;
	scanf("%d %d",&N,&S);

	vector<pair<int,int> > v(N);
	vector<int> dp(N);
	for (int i=0; i<N; i++){
		pair<int,int> p;
		scanf("%d %d",&p.first,&p.second);
		v[i] = p;
	}

	sort(v.begin(), v.end());

	for (int i=0; i<v.size(); i++){
		dp[i] = v[i].second;
	}
	for (int i=0; i<v.size(); i++){
		int x = binary_search(v[i].first+S, v);
		int y = binary_search(v[x].first+S, v);
		if (x < v.size()){
			for (int j=x; j<y && j < v.size() ; j++){
				dp[j] = (dp[j] < dp[i] + v[j].second) ? dp[i] + v[j].second : dp[j];
			}
		}
	}
	int max =0;
	for (auto i: dp){
		if (max < i)
			max = i;
	}
	printf("%d\n", max);
	
}