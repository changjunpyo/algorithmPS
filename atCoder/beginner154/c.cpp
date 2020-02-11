#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int arr[200000];
	for (int i=0; i<N; i++){
		scanf("%d",&arr[i]);
	}

	sort(arr, arr+N);

	int pre = arr[0];

	for (int i=1; i<N; i++){
		if (pre == arr[i]){
			printf("NO\n");
			return 0;
		}
		pre = arr[i];
	}
	printf("YES\n");
}