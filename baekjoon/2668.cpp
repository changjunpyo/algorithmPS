#include <cstdio>
using namespace std;

int main(){
	int N;
	int arr[101];
	bool check[101]={false,};
	int cnt=0;
	scanf("%d",&N);
	for (int i=1; i<=N; i++){
		scanf("%d",&arr[i]);
	}

	for (int i=1; i<=N; i++){
		if (check[i])
			continue;
		int next = arr[i];
		bool visited[101]={false,};
		visited[i] = true;
		while (!visited[next]){
			visited[next] = true;
			next = arr[next];
		}

		if (next == i){
			check[i] = true;
			cnt++;
			next = arr[i];
			while (next != i){
				check[next] = true;
				cnt++;
				next = arr[next];
			}
		}
	}
	printf("%d\n",cnt );
	for (int i=1; i<=N; i++){
		if (check[i])
			printf("%d\n",i );
	}
}