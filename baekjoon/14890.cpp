#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	int N, L;
	int map[100][100];
	scanf("%d %d",&N,&L);

	for (int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			scanf("%d",&map[i][j]);
	}
	int ans=0;
	for (int i=0; i<N; i++){
		bool flag=true;
		bool check[100] ={false};
		int prev= map[i][0];
		for(int j=1; j<N; j++){
			if (prev == map[i][j])
				continue;
			int cek = abs(prev - map[i][j]);
			if (cek >1){
				flag=false;
				break;
			}
			if (prev - map[i][j] == 1){
				for (int k=0; k<L; k++){
					if (k+j > N-1 || prev - map[i][k+j] != 1){
						flag = false;
						break;
					}
					check[k+j]= true;
				}
				if (!flag)
					break;
				else{
					j+= L-1;
				}
			}
			else if (prev - map[i][j] == -1){
				for (int k=1; k<L+1; k++){
					if ( j-k < 0 ||check[j-k]  || prev - map[i][j-k] != 0){
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
			prev = map[i][j];
		}
		if (flag){
			ans++;
		}
	}
		for (int i=0; i<N; i++){
		bool flag=true;
		bool check[100] ={false};
		int prev= map[0][i];
		for(int j=1; j<N; j++){
			if (prev == map[j][i])
				continue;
			int cek = abs(prev - map[j][i]);
			if (cek>1){
				flag=false;
				break;
			}
			if (prev - map[j][i] == 1){
				for (int k=0; k<L; k++){
					if (k+j > N-1 ||check[j+k] || prev - map[k+j][i] != 1){
						flag = false;
						break;
					}
					check[k+j]= true;
				}
				if (!flag)
					break;
				else{
					j+= L-1;
				}
			}
			else if (prev - map[j][i] == -1){
				for (int k=1; k<L+1; k++){
					if ( j-k < 0 ||check[j-k]   || prev - map[j-k][i] != 0){
						flag = false;
						break;
					}
					check[j-k]= true;
				}
				if (!flag)
					break;
			}
			prev = map[j][i];
		}
		if (flag){
			ans++;
		}
		}

		printf("%d\n", ans);
		return 0;
}