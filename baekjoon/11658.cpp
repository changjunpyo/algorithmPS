#include <bits/stdc++.h>
using namespace std;
void update(vector<vector<int> > &t, int i, int j, int diff){
	while(i< t.size()){
		int change_j = j;
		while(change_j< t[i].size()){
			t[i][change_j] += diff;
			change_j += (change_j & -change_j);
		}
		i += (i & -i);
	}
}

int sum(vector<vector<int> > &t, int i, int j){
	int ans=0;
	while(i>0){
		int change_j = j;
		while(change_j>0){
			ans += t[i][change_j];
			change_j -= (change_j & -change_j);
		}
		i -= (i & -i);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >>M;
	vector<vector<int> > a(N+1, vector<int>(N+1));
	vector<vector<int> > t(N+1, vector<int>(N+1));

	for(int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			int num;
			cin >>a[i][j];
			update(t,i,j,a[i][j]);
		}
	}

	while(M--){
		int w,x1,x2,y1,y2,c;
		cin >>w;
		if (w==0){
			cin >> x1 >> y1>> c;
			update(t,x1,y1,c-a[x1][y1]);
			a[x1][y1] = c;
		}
		else {
			cin >> x1 >> y1 >>x2>> y2;
			cout <<sum(t,x2,y2)- sum(t,x2,y1-1) -sum(t,x1-1,y2) + sum(t,x1-1,y1-1)<<"\n"; 
		}
	}
}