#include <bits/stdc++.h>
using namespace std;

void update(vector<long long> &tree, int i, long long diff){
	while(i <tree.size()){
		tree[i] += diff;
		i += (i &-i);
	}
}

long long sum(vector<long long> &tree , int i){
	long long ans = 0;
	while(i >0){
		ans += tree[i];
		i -= (i& -i);
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >>n;
	vector<long long> a(n+1);
	vector<long long> t(n+1);
	for (int i=1; i<=n; i++){
		int num;
		cin >>num;
		a[num] = i;
	}
	int left=1;
	int right=n;
	bool turn_left=true;
	while (left <= right){
		if (left == right){
			cout <<0 <<"\n";
			break;
		}
		int flpos =  a[left];
		int frpos = a[right];
		if (turn_left){
			if (flpos <=1)
				cout << 0<<"\n";
			else{
				//cout <<flpos <<" " << 1 <<" " <<sum(t,flpos)<<" " <<sum(t,left)<<"\n";
				cout <<flpos - 1 -(sum(t,flpos)- (sum(t,0)))<<"\n";
			}
			update(t,a[left],1);
			left++;
		}
		else {
			if (frpos >= n)
				cout <<0<<"\n";
			else
				cout <<n - frpos - (sum(t,n) - sum(t,frpos))<<"\n";
			update(t,a[right],1);
			right--;
		}
		turn_left = !turn_left;

	}
	return 0;
}