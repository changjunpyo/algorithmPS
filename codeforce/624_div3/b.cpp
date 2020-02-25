#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);

int main(){
	fastio
	int t;
	cin >>t;
	while(t--){
		int n,m;
		cin >>n>>m;
		vector<int> arr(n);
		vector<int> dist(m, 0);
		vector<int> ans[100];
		vector<int> t;
		for (int i=0; i<n; i++)
			cin >>arr[i];
		for (int i=0; i<m; i++)
			cin >>dist[i];
		sort(dist.begin(), dist.end());
		int idx =0;
		int val = dist[idx];
		int at=-1;
		for (int i=0; i<n; i++){
			if (idx == m || i < dist[idx]-1){
				at++;
				ans[at].push_back(arr[i]);
			}
			if (i == dist[idx]-1){
				at++;
				ans[at].push_back(arr[i]);

			}
			else if (i == dist[idx]){
				ans[at].push_back(arr[i]);
				idx++;
			}
		}
		
		vector<int> zzz;
		for (int i=0; i<at+1; i++){
			sort(ans[i].begin(), ans[i].end());
			for (auto x: ans[i])
				zzz.push_back(x);
		}
		bool flag =true;
		for (int i=0; i<n-1; i++){
			if (zzz[i] > zzz[i+1]){
				flag = false;
				break;
			}

		}
		if (flag)
			cout <<"YES"<<"\n";
		else
			cout <<"NO"<<"\n";
		

	}	
}