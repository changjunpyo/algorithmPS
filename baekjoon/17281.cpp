#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int arr[50][9];
	for (int i=0; i<N; i++){
		for (int j=0; j<9; j++)
			scanf("%d", &arr[i][j]);
	}

	vector <int> x={0,1,2,3,4,5,6,7,8};
	int mx =0;
	do{ 
		if (x[3] != 0)
			continue;
		int pt=0;
		int inning = 0;
		int batter = 0;
		int out =0;
		int base[4] = {1,0,0,0};
		while(inning < N){
			while(out <3){
				int ret =arr[inning][x[batter]];
				if (ret ==0)
					out++;
				else {
					for (int i=3; i>=0 ; i--){
						if (base[i]){
							if (i+ ret >=4)
								pt++;
							else
								base[i+ret] = 1;
							base[i] = 0;
						}
					}
				}
				base[0] =1;
				batter = (batter+1)%9;
			}
			inning++;
			base[0] =1;
			base[1]=0;
			base[2]=0;
			base[3]=0;
			out =0;
		}
		mx = max(pt, mx);
	} while (next_permutation(x.begin(), x.end()));
		
	printf("%d\n",mx );
}