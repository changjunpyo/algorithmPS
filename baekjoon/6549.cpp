#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long solve(int left, int right, vector<long long int> &v){
	// 1) base case
	if (left == right)
		return v[left];
	int mid = (left+ right)/2;
	// 2) Divide
	long long ret = max(solve(left,mid,v),solve(mid+1,right,v));
	
	// 3) conquer
	int l = mid , r = mid+1;
	long long height = min(v[l],v[r]);

	ret = max(ret, height*2);

	while(left < l || r < right){
		if (r < right && ((l == left) || v[l-1] < v[r+1])){
			r++;
			height = min(v[r], height);
		}
		else{
			l--;
			height = min(v[l], height);
		}

		ret = max(ret, height*(r-l+1));
	}
	return ret;
}


int main(){
	
	while(1){
		int N;
		scanf("%d",&N);
		if (N== 0)
			break;
		vector<long long int> h(N);
		for (int j=0; j<N; j++)
			scanf("%lld",&h[j]);

		printf("%lld\n",solve(0,N-1,h));
	}
}
