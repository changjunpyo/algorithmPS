#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);


int main(){
	fastio
	int t;
	cin >>t;
	while(t--){
		int n,m;
		string s;
		cin >>n>>m;
		cin >>s;
		int ans[26]={0,};
		vector<int> arr(m+1);
		for (int i=0; i<m; i++){
			cin >>arr[i];
		}
		sort(arr.begin(), arr.end(), greater<int>());

		int count =1;
		int idx=0;
		int val=arr[idx]-1;
		for (int i=s.size()-1; i>=0; i--){
			while(idx < m &&i <= val){
				count++;
				idx++;
				val = arr[idx]-1;
			}
			ans[s[i]-'a'] += count;
		}
		for (int i=0; i<26; i++)
			cout <<ans[i]<<" ";
		
		cout<<"\n";
	}	
}