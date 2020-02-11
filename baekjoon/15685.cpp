#include <cstdio>
#include <vector>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
bool map[101][101]={false,};

void make_dragon_curve(int y, int x, int now_gen,int gen, vector<int> &v){
	if (now_gen > gen){
		return ;
	}
	int new_x = x;
	int new_y = y;
	int idx = v.size()-1;
	for (int i=idx; i>=0; i--){
		new_x += dx[(v[i]+1)%4];
		new_y += dy[(v[i]+1)%4];
		map[new_x][new_y] = true;
		v.push_back((v[i]+1)%4);
	}

	make_dragon_curve(new_y,new_x,now_gen+1,gen,v);
}

int main(){
	int N,ans=0;
	scanf("%d",&N);

	for (int i=0; i<N; i++){
		int y,x,gen,dir;
		vector<int> v;
		scanf("%d %d %d %d",&x,&y,&dir,&gen);
		map[x][y] = true;
		y += dy[dir];
		x += dx[dir];
		map[x][y] = true;
		v.push_back(dir);
		make_dragon_curve(y,x,1,gen,v);
	}

	for (int i=0; i<100; i++){
		for (int j=0; j<100; j++){
			if (map[i][j] && map[i+1][j] && map[i][j+1]&& map[i+1][j+1])
				ans++;
		}
	}
	printf("%d\n",ans);
}