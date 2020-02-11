#include <cstdio>
#include <unordered_set>
using namespace std;
unordered_set<int> arr;
int main(){
	int N;
	int M;
	scanf("%d",&N);
	while(N--){
		int a;
		scanf("%d",&a);
		arr.insert(a);
	}
	scanf("%d",&M);

	for (int i=0; i<M; i++){
		int d;
		scanf("%d",&d);
		if (arr.find(d) != arr.end() )
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}