#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[5000000]={0,};
int main(){
	int N;

	scanf("%d",&N);
	long long sum=0;
	for (int i=0; i<N; i++){
		scanf("%d",&arr[i]);
		sum+= arr[i];
	}

	sort(arr, arr+N);&
	int x = sum/N;
	int y = x+1;
	long long a=0;
	long long b=0;
	for (int i=0; i<N; i++){
		a+= (arr[i]-x)*(arr[i]-x);
		b+= (arr[i]-y)*(arr[i]-y);
	}
	int ans;
	if (a <= b)
		ans =x;
	else
		ans =y;
	if (N%2 ==0)
		printf("%d %d\n",arr[N/2-1],ans);
	else
		printf("%d %d\n",arr[N/2],ans);
}