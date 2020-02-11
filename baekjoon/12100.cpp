#include <cstdio>
#include <algorithm>
using namespace std;
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
int map[20][20];
bool visited[20][20]={false,};

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int maxSum(int N){
	int mx = 0;
	for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				mx+= map[i][j];
			}
	}
	return mx;
}
int maxMap(int N){
	int mx = 0;
	for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (mx < map[i][j])
					mx = map[i][j];
			}
	}
	return mx;
}

void moveAndMerge(int N, int dir){

	if (dir == NORTH){
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (map[i][j]==0)
					continue;
				int y = i;
				int x = j;
				while (y > 0 && (map[y][x] == map[y-1][x] || map[y-1][x] == 0) && !visited[y-1][x]){
					if (map[y][x] == map[y-1][x]){
						map[y-1][x] *= 2;
						map[y][x] =0;
						visited[y-1][x]= true;
						break; 
					}
					else if (map[y-1][x] == 0){
						swap(map[y-1][x], map[y][x]);
					}
					y--;
				}
			}
		}
	}
	else if (dir == EAST){
		for (int j=N-1; j>=0; j--){
			for (int i=0; i<N; i++){
				if (map[i][j]==0)
					continue;
				int y = i;
				int x = j;
				while (x < N-1 && (map[y][x] == map[y][x+1] || map[y][x+1] == 0) && !visited[y][x+1]){
					if (map[y][x] == map[y][x+1]){
						map[y][x+1] *= 2;
						map[y][x] =0;
						visited[y][x+1]= true;
						break; 
					}
					else if (map[y][x+1] == 0){
						swap(map[y][x+1], map[y][x]);
					}
					x++;
				}
			}
		}
	}
	else if (dir == SOUTH){
		for (int i=N-1; i>=0; i--){
			for (int j=0; j<N; j++){
				if (map[i][j]==0)
					continue;
				int y = i;
				int x = j;
				while (y < N-1 && (map[y][x] == map[y+1][x] || map[y+1][x] == 0) && !visited[y+1][x]){
					if (map[y][x] == map[y+1][x]){
						map[y+1][x] *= 2;
						map[y][x] =0;
						visited[y+1][x]= true;
						break; 
					}
					else if (map[y+1][x] == 0){
						swap(map[y+1][x], map[y][x]);
					}
					y++;
				}
			}
		}
	}
	else if (dir == WEST){
		for (int j=0; j<N; j++){
			for (int i=0; i<N; i++){
				if (map[i][j]==0)
					continue;
				int y = i;
				int x = j;
				while (x > 0 && (map[y][x] == map[y][x-1] || map[y][x-1] == 0) && !visited[y][x-1]){
					if (map[y][x] == map[y][x-1]){
						map[y][x-1] *= 2;
						map[y][x] =0;
						visited[y][x-1]= true;
						break; 
					}
					else if (map[y][x-1] == 0){
						swap(map[y][x-1], map[y][x]);
					}
					x--;
				}
			}
		}
	}


}

int moveAction(int N, int cnt){
	//base case : 5번 돌면 끝
	if (cnt == 5){
		return maxMap(N);
	}


	
	int mx = 0;
	for (int i=0; i<4; i++){
		int copy_map[20][20];
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				copy_map[i][j] = map[i][j];
				visited[i][j] = false;
			}
		}
		moveAndMerge(N, i);
		int ret = moveAction(N,cnt+1);
		if (ret > mx)
			mx = ret;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				map[i][j] = copy_map[i][j];	
			}
		}

	}

	return mx;

}

int main(){
	int N;
	scanf("%d",&N);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++)
			scanf("%d",&map[i][j]);
	}

	printf("%d\n",moveAction(N,0));

}