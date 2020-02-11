#include <cstdio>
#include <vector>
using namespace std;
const int dx[4] ={1,0,-1,0};
const int dy[4] ={0,1,0,-1};




int main(){
	vector<pair<int,int> > snake;
	snake.push_back(make_pair(1,1));
	int N,numApple;
	scanf("%d",&N);
	scanf("%d",&numApple);
	vector<pair<int,int> > apple(numApple);
	vector<bool> ate(numApple);
	for (int i=0; i<numApple; i++){
		scanf("%d %d",&apple[i].second,&apple[i].first);
		ate[i]= false;
	}
	int changeDirNum;
	scanf("%d",&changeDirNum);
	vector<pair<int,char> > changeDir(changeDirNum);
	for (int i=0; i<changeDirNum; i++)
		scanf("%d %c",&changeDir[i].first,&changeDir[i].second);
	int change_idx =0;
	int change_time = changeDir[change_idx].first;
	char change_dir = changeDir[change_idx].second;
	int t = 0, dir=0;
	int x = 1, y=1;
	bool eat_apple=false;
	while ( t <10000){
		t++;
		x += dx[dir], y+= dy[dir];
		if (x < 1 || x >N || y < 1 || y >N){
			printf("%d\n",t);
			return 0;
		}
		else {
		
			// 자기 몸 부딪치는지 확인
			for (auto p: snake){
				if (x == p.first && y== p.second){
					printf("%d\n", t);
					return 0;
				}
			}
			snake.insert(snake.begin(),make_pair(x,y));
			for (auto& a: apple){
				int pos = &a - &apple[0];
				eat_apple = false;
				if (ate[pos])
					continue;
				if (x == a.first && y== a.second){
					eat_apple= true;
					ate[pos]= true;
					break;
				}
			}
			if (!eat_apple){
				snake.pop_back();
			}
			
			
		}
		if (change_time == t){
			if (change_dir == 'D')
				dir = (dir+1)%4;
			else
				dir = (dir+3)%4;

			change_idx++;
			if (change_idx == changeDirNum)
				change_time = 0;
			else{
				change_time = changeDir[change_idx].first;
				change_dir = changeDir[change_idx].second;
			}
		}

	}
	printf("%d\n", t);
	return 0;

}