#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
long long int height_sum[300]={0,};
int find_height(long long int num, int k){
	if (k==1)
		return num;

	else {
		int lo = 0;
		int hi = 200;
		int mid ;
		while (lo+1 < hi){
			mid = (lo+ hi)/2;
			if (num <= ((pow(k,mid) -1)/(k-1)))
				hi = mid;
			else
				lo = mid;
		}
		return hi;
	}
}


int find_LCA(long long int x, long long int y, int height_x, int height_y, int k ){
	
	// 같은 높이로 만듬
	while(height_y != height_x){
		int i=1;
		while(height_y <= height_x-i)
			i*=2;
		i/=2;
		x += height_sum[i];
		x /= pow(k,i);
		height_x -= i;
	}
	int height = height_x;
	while(x != y){
		long long int _x  = (x+height_sum[1])/ pow(k,1);
		long long int _y  = (y+height_sum[1])/ pow(k,1);
		if (_x == _y){
			x=_x;
			y=_y;
			height--;
			break;
		}
		int count;
		for (int i=2;; i*=2){
			long long int check_x  = (x+height_sum[i])/ pow(k,i);
			long long int check_y  = (y+height_sum[i])/ pow(k,i);
			if (check_x == check_y){
				count = i/2;
				break;
			}
		}
		x = (x+height_sum[count])/ pow(k,count);
		y = (y+height_sum[count])/ pow(k,count);
		height-= count;
	}
	return height;
}

int main(){
	long long int N;
	int K,Q;
	scanf("%lld %d %d",&N,&K,&Q);
	long long int sum =0;
	for (int i=0; i<299; i++){
		sum += pow(K,i);
		height_sum[i+1] = sum*(K-2);
	}

	for (int i=0; i<Q; i++){
		long long int x, y;
		scanf("%lld %lld",&x,&y);
		if (K==1)
			printf("%lld\n", abs(y-x));
		else{
			int height_x = find_height(x,K);
			int height_y = find_height(y,K);
			long long int ans = height_x + height_y;
			if (x > y)
				ans -= (find_LCA(x,y,height_x,height_y,K))*2;
			else
				ans -= (find_LCA(y,x,height_y,height_x,K))*2;

			printf("%lld\n",ans);
		}		
	}
}