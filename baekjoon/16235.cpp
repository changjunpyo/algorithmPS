#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};

int main(){
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);

	int a[11][11];
	int map[11][11];
	int now_die[11][11]={0,};
	for (int i=1; i<=N;i++){
		for (int j=1; j<=N; j++){
			scanf("%d",&a[i][j]);
			map[i][j] = 5;
		}
	}
	vector<int> v[11][11];
	for (int i=0; i<M; i++){
		int row,col,age;
		scanf("%d %d %d",&row,&col,&age);
		v[row][col].push_back(age);
	}

	int y = 0;
	while (y != K){
	// spring 
	// r,c,나이순으로 정렬
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			sort(v[i][j].begin(), v[i][j].end());
			vector<int>::iterator it = v[i][j].begin();
			int died=0;
			for (auto& a: v[i][j]){
				if (map[i][j] >= a){
					map[i][j] -= a;
					a++;
					it++;
				}
				else {
					died += (a/2);
				}
			}
			map[i][j] += died;
			v[i][j].erase(it, v[i][j].end());
		}	
	}

	//fall
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			for (auto a: v[i][j]){
				if (a % 5 ==0){
					for (int d=0; d<8; d++){
						int r = i+ dx[d];
						int c = j+ dy[d];
						if (r>0 && r<=N && c>0 && c<=N){
							v[r][c].push_back(1);
						}
					}
				}
			}
		}
	}
	// winter 
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			map[i][j] += a[i][j];
		}
	}
		y++;
	}
	int sum =0;
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			sum += v[i][j].size();
		}
	}
	printf("%d\n",sum );
}