#include <cstdio>
#include <queue>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int ans=987654321;

int bfs(queue<pair<int,int> > &q,int map[50][50],int N,int count){
	int t=0;
	while (!q.empty()){
		t++;
		if (t >= ans)
			return 987654321;
		bool flag=true;
		vector< pair<int,int> > v;
		while(!q.empty()){
			pair<int,int> p = q.front();
			q.pop();
			v.push_back(p);
		}
		for (auto p : v){
			for (int i=0; i<4; i++){
				int x = p.first+ dx[i];
				int y = p.second + dy[i];
				if ( x>=0 && y>=0 && x<N && y<N){
					if (map[x][y] == 0){
						map[x][y] = 3;
						q.push(make_pair(x,y));
						count--;
						if (count == 0)
							return t;
					}
					if (map[x][y] == 2){
						map[x][y] = 3;

						q.push(make_pair(x,y));
					}
				}
			}
		}
		
	}
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (map[i][j] == 0){
				t=987654321;
				break;
			}
		}
		if (t==987654321)
			break;
	}
	return t;
}

void make_virus_variation(vector<vector<int> > &list, vector<int> &v,int idx,int M,int max_virus){
	if (v.size() == M){
		list.push_back(v);
		return ;
	}
	for (int i=idx; i<max_virus; i++){
		v.push_back(i);
		make_virus_variation(list,v,i+1,M,max_virus);
		v.pop_back();
	}
	return;

}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);

	int map[50][50];
	int copy_map[50][50];
	int count=0;
	vector<pair<int,int> > virus;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d",&map[i][j]);
			if (map[i][j] ==2)
				virus.push_back(make_pair(i,j));
			if (map[i][j] ==0)
				count++;
		}
	}
	if (count == 0){
		printf("0\n");
		return 0;
	}
	
	vector < vector<int> > v;
	vector <int> temp;
	make_virus_variation(v,temp, 0,M, virus.size());
	
	for (auto a: v){
		for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			copy_map[i][j] = map[i][j];
		}
		}
		queue<pair<int,int> > q;
		for (auto b: a){
			copy_map[virus[b].first][virus[b].second] =3;
			q.push(virus[b]);

		}
		int ret = bfs(q,copy_map,N,count);
		ans = min(ret,ans);
	}
	if (ans == 987654321)
		ans =-1;
	printf("%d\n",ans );


}