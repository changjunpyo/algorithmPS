#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int dy[4] ={-1,0,0,1};
const int dx[4] ={0,-1,1,0};
int map[20][20];
int visited[20][20];
int cnt[7]={0,};
int x,y;
int shark_size=2;
int eat_cnt =0;


// 자기보다 사이즈가 작은게 있는지 확인
bool check_eatable(){
	

	for (int i=0; i<shark_size; i++){
		if (shark_size > 6)
			break;
		if (cnt[i]>0)
			break;
		
		if(i== shark_size-1)
			return false;
	}
	return true;
}

int bfs(int N){
	visited[y][x] = true;
	queue<pair<pair<int,int>, int> > q;
	q.push(make_pair(make_pair(y,x), 0));
	vector<pair<int,int> > v; 
	int chk_t=-1;
	while(!q.empty()){
		pair<pair<int,int>, int> p = q.front();
		q.pop();
		if (chk_t != -1 && p.second == chk_t)
			break;
		for (int i=0; i<4; i++){
			int y_move = dy[i] + p.first.first;
			int x_move = dx[i] + p.first.second;
			int t = p.second+1;

			if (y_move >=0 && y_move<N && x_move >=0 && x_move<N && !visited[y_move][x_move]){
				if (map[y_move][x_move] !=0 && map[y_move][x_move] <shark_size){
					chk_t = t;
					v.push_back(make_pair(y_move,x_move));
				}
				else if (map[y_move][x_move] == 0 || map[y_move][x_move] == shark_size){
					q.push(make_pair(make_pair(y_move,x_move), t));
					visited[y_move][x_move]= true;
				}
			}
		}
	}
	if (chk_t > 0){
		sort(v.begin(), v.end());
		map[y][x]=0;
		y = v[0].first;
		x = v[0].second;
		cnt[map[y][x]]--;
		map[y][x]=9;
		return chk_t;
	}
	return -1;
}

int main(){
	int N;
	scanf("%d",&N);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d",&map[i][j]);
			if (map[i][j] == 9){
				y= i;
				x= j;
			}
			else if (map[i][j] >0)
				cnt[map[i][j]]++;
		}
	}
	int t=0;
	while(1){
		if (!check_eatable())
			break;

		int ret = bfs(N);
		if (ret == -1)
			break;
		else{
			t+= ret;
			eat_cnt++;
			if (eat_cnt == shark_size){
				shark_size++;
				eat_cnt=0;
			}
		}
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				visited[i][j] = false;
			}
		}
	}
	printf("%d\n", t);


}