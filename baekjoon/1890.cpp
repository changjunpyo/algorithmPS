#include <cstdio>
using namespace std;

int map[100][100];
long long int cache[100][100];
int N;
long long int jump(int x, int y){
	long long int &ret = cache[x][y];
	if (ret != -1)
		return ret;
	if (x == N-1 && y == N-1)
		return ret = 1;
	int dx = x + map[x][y];
	int dy = y + map[x][y];
	long long int lret = 0;
	long long int rret = 0;
	if (dx >=0 && dx <N && dx != x)
		lret = jump(dx, y);
	if (dy >=0 && dy <N && dy != y)
		rret = jump(x, dy);

	return ret = (lret + rret);
}	

int main(){
	scanf("%d",&N);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d",&map[i][j]);
			cache[i][j] =-1;
		}
	}

	printf("%lld\n",jump(0,0));


}