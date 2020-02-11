#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N;
	queue<int> q;
	scanf("%d",&N);
	for (int i=1; i<N+1; i++){
		q.push(i);
	}

	while(q.size() != 1){
		q.pop();
		int f = q.front();
		q.pop();
		q.push(f);
	}

	printf("%d\n",q.front());
}