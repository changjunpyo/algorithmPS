#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int arr[1000001]={0,};
	int pre_pre = 1;
	int pre = 2;
	int ans;
	for (int i=2; i<N; i++){
		ans = (pre+ pre_pre) %15746;
		pre_pre = pre;
		pre = ans;
	}
	if (N==1)
		printf("1\n");
	else if(N==2)
		printf("2\n");
	else 
		printf("%d\n",ans);
}