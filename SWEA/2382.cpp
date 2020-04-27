#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int dx[5]={0,-1,1,0,0};
const int dy[5]={0,0,0,-1,1};
int map[100][100]={0};
vector<vector<int> > minimi(1001, vector<int>(4,0));
int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		int N, M, K;
		cin >>N >>M >>K;
		memset(map, 0, sizeof(map));
		for (int i=1; i<=K; i++){
			for (int j=0; j<4; j++){
				cin >>minimi[i][j];
			}
			map[minimi[i][0]][minimi[i][1]] = i;
		}

		
		for (int a=0 ; a<M; a++){
			int next_map[100][100]={0,};
			int mx[100][100] ={0,};
			for (int i=1; i<=K; i++){
				if (minimi[i][2] ==0) continue;
				int new_x = minimi[i][0] + dx[minimi[i][3]];
				int new_y = minimi[i][1] + dy[minimi[i][3]];
				if (new_x ==0 || new_x==N-1 || new_y ==0 || new_y ==N-1 ){
					minimi[i][0] = new_x;
					minimi[i][1] = new_y;
					minimi[i][2] /=2;
					if (minimi[i][2] == 0) continue;
					if (minimi[i][3] %2 ==0)
						minimi[i][3]--;
					else  
						minimi[i][3]++;
					next_map[new_x][new_y] = i;
				}

				else if (next_map[new_x][new_y]>0){
					if (minimi[i][2] < mx[new_x][new_y]){
						minimi[next_map[new_x][new_y]][2] += minimi[i][2];
						minimi[i][2] = 0;
					}
					else{
						mx[new_x][new_y] = minimi[i][2];
						minimi[i][2] += minimi[next_map[new_x][new_y]][2];
						minimi[next_map[new_x][new_y]][2] =0;
						minimi[i][0] = new_x;
						minimi[i][1] = new_y;

						next_map[new_x][new_y] = i;
					}
				}
				else {
					minimi[i][0] = new_x;
					minimi[i][1] = new_y;
					next_map[new_x][new_y] = i;
					mx[new_x][new_y] = minimi[i][2];
				}
			}
			for (int i=0; i<N; i++){
				for (int j=0; j<N; j++){
					map[i][j] = next_map[i][j];
				}
			}
		}
		int ans =0;
		for (int i=1; i<=K; i++){
			if (minimi[i][2] ==0) continue;
			else{
				ans += minimi[i][2];
			}
		}

		cout <<"#"<<t<<" "<<ans<<"\n";
	}
}