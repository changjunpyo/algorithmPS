#include <cstdio>
using namespace std;
int map[100][100];
int cache[100][100];


int jump(int y, int x, int N){
    // base case
    if (y>=N || x>=N) return 0;
    if (y==N-1 && x==N-1) return 1;
    int &ret = cache[y][x];
    
    if (ret != -1)
    {
        return ret;
    }
    return ret = jump(y,x+map[y][x],N) || jump(y+map[y][x],x,N);
}


int main(){
    int T;
    scanf("%d",&T);
    for (int t = 0; t < T; t++)
    {   int N;
        scanf("%d",&N);
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                scanf("%d", &map[i][j]);
                cache[i][j] = -1;
            }
        }
        if (jump(0,0,N) == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;



    
}