#include <cstdio>
#include <queue>
using namespace std;

int map[8][8]={0,};
int copy_map[8][8]={0,};
bool visited[8][8]={false};
void make_map(int f_x,int f_y, int s_x, int s_y, int t_x, int t_y, int N, int M){
	for (int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if (i==f_y && j==f_x)
				copy_map[i][j] = 1;
			else if (i==s_y && j==s_x)
				copy_map[i][j] = 1;
			else if (i==t_y && j==t_x)
				copy_map[i][j] = 1;
			else
				copy_map[i][j] = map[i][j];
		}
	}
	return ;
}
int bfs(int N, int M){
	queue<pair<int, int>> q;

	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (copy_map[i][j]== 2){
				q.push(make_pair(i,j));
				visited[i][j] = true;
			}
		}
	}

	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		if (p.first > 0 && !visited[p.first-1][p.second] && copy_map[p.first-1][p.second] == 0){
			q.push(make_pair(p.first-1, p.second));
			visited[p.first-1][p.second] = true;
			copy_map[p.first-1][p.second] = 2;
		}
		if (p.first < N-1 && !visited[p.first+1][p.second]&& copy_map[p.first+1][p.second] == 0){
			q.push(make_pair(p.first+1, p.second));
			visited[p.first+1][p.second] = true;
			copy_map[p.first+1][p.second] = 2;
		}
		if (p.second > 0 && !visited[p.first][p.second-1]&& copy_map[p.first][p.second-1] == 0){
			q.push(make_pair(p.first, p.second-1));
			visited[p.first][p.second-1] = true;
			copy_map[p.first][p.second-1] = 2;
		}
		if (p.second < M-1 && !visited[p.first][p.second+1]&& copy_map[p.first][p.second+1] == 0){
			q.push(make_pair(p.first, p.second+1));
			visited[p.first][p.second+1] = true;
			copy_map[p.first][p.second+1] = 2;
		}
	}
	int count =0;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			visited[i][j] = false;
			if (copy_map[i][j] == 0)
				count++;
		}
	}

	return count; 
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);

	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			scanf("%d",&map[i][j]);
		}
	}

	int f_x, f_y;
	int s_x, s_y;
	int t_x, t_y;
	int max=0;
	for (f_y=0; f_y<N; f_y++){
		for (f_x=0; f_x<M; f_x++){
			if (map[f_y][f_x] != 0)
				continue;
			for (s_y=0; s_y<N; s_y++){
				for (s_x=0; s_x<M; s_x++){
					if (map[s_y][s_x] != 0 || (s_y < f_y ||(s_y == f_y && s_x <= f_x)) )
						continue;
					for (t_y=0; t_y<N; t_y++){
						for (t_x=0; t_x<M; t_x++){
							if (map[t_y][t_x] != 0 || (t_y < s_y || (t_y == s_y && t_x <= s_x)))
								continue;
							
							make_map(f_x,f_y,s_x,s_y,t_x,t_y,N,M);
							int ctn = bfs(N,M);
							if (max < ctn)
								max = ctn;
						}
					}
				}
			}


		}
	}

	printf("%d\n",max );
}