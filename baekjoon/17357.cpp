#include <cstdio>
using namespace std;
long long int s[1000001]={0,};
long long int ss[1000001]={0,};

long long int variation(int a, int b, int k){
	long long int x = ss[b] - ss[a-1];
	long long int y = s[b] - s[a-1];
	return (x*k -y*y);
}
int main(){
	int N;
	scanf("%d",&N);

	for (int i=1; i<=N; i++){
		long long int a;
		scanf("%lld",&a);
		if (i==1){
			s[i] = a;
			ss[i] = a*a;
		}
		else {
			s[i] = s[i-1] + a;
			ss[i] = ss[i-1] + a*a;
		}
	}

	for (int k=1; k<=N; k++){
		long long int mx = -1;
		int idx = -1;
		for (int j=1; j<=N-k+1; j++){
			long long int ret = variation(j,j+k-1, k);
			if (ret > mx){
				idx = j;
				mx = ret;
			} 
		}
		printf("%d\n",idx );
	}


}