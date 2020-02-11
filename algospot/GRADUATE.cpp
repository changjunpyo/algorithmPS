#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int prerequisite[12]={0,};
int classes[10]={0,};
int cache[10][(1<< 12)-1];
int C,N,K,M,L;
// __builtin_popcount

int graduate(int semester, int taken){
	if (__builtin_popcount(taken) >= K)
		return 0;
	if (semester == M)
		return 987654321;
	int &ret = cache[semester][taken];

	if (ret != -1)
		return ret;
	ret = 987654321;

	int canTake = (classes[semester] & ~taken);

	for (int i=0; i<N; i++){
		if ((canTake & (1 <<i)) && (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1<<i);
	}

	for(int take = canTake; take>0; take = ((take-1)& canTake)){
		if(__builtin_popcount(take) > L)
			continue;
		ret = min(ret, graduate(semester+1, taken | take) +1);
	}
	ret = min(ret, graduate(semester+1,taken));
	return ret;
}

int main(){
	scanf("%d",&C);

	while(C--){
		memset(cache, -1, sizeof(cache));
		scanf("%d %d %d %d",&N,&K,&M,&L);
		for(int i=0; i<N; i++){
			int prerequisite_num;
			scanf("%d",&prerequisite_num);
			prerequisite[i]=0;
			for (int j=0; j<prerequisite_num; j++){
				int pre;
				scanf("%d",&pre);
				prerequisite[i] |=  (1 <<pre);
			}
		}

		for (int i=0; i<M; i++){
			int classes_num;
			scanf("%d",&classes_num);
			classes[i]=0;
			for (int j=0 ; j<classes_num; j++){
				int cla;
				scanf("%d",&cla);
				classes[i] |= (1<< cla);
			}
		}
		int ans = graduate(0,0);
		if (ans == 987654321)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);

	}
}