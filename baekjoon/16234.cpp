#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1, 0,-1};
int map[50][50];
bool visited[50][50]={false,};
int main(){
	int N,L,R;
	scanf("%d %d %d",&N,&L,&R);

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			scanf("%d",&map[i][j]);
		}
	}
	queue<pair<int,int> > q;
	int t=0;
	bool changed= false;
	while(1){
		changed =false;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (visited[i][j])
					continue;
				q.push(make_pair(i,j));
				visited[i][j] = true;
				int sum =0;
				vector<pair<int,int> > list;
				while(!q.empty()){
					pair<int,int> p = q.front();
					q.pop();
					for (int k=0; k<4; k++){
						int x = p.first+ dx[k];
						int y = p.second + dy[k];
						if (x>=0 && x<N && y >=0 && y<N && !visited[x][y]){
							int diff = abs(map[x][y]- map[p.first][p.second]);
							if (L <= diff && diff <= R){
								changed = true;
								visited[x][y]= true;
								sum += map[x][y];
								list.push_back(make_pair(x,y));
								q.push(make_pair(x,y));
							}
						} 
					}
				}
				if (list.size() != 0){
						list.push_back(make_pair(i,j));
						sum += map[i][j];
				}
				for (int k=0; k<list.size(); k++){
					map[list[k].first][list[k].second] = (sum/(int)list.size());
				}
			}
		}	
		if (!changed)
			break;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++)
				visited[i][j] = false;
		}
		t++;
	}
	printf("%d\n", t);
}