#include <iostream>
using namespace std;
const int dx[4] ={-1,1,0,0};
const int dy[4] ={0,0,-1,1};
pair<int,int> smell[21][21]={};
int map[21][21]={0,};
int N,M,k;
class Shark
{
public:
	int num;
	int dir;
	int priority[4][4];
	int x,y;

	void move(){
		for (int i=0; i<4; i++){
			int next = priority[dir-1][i]-1;
			int new_x = dx[next] + x;
			int new_y = dy[next] + y;
			if (new_x >= 0 && new_x< N && new_y >= 0 && new_y < N && smell[new_x][new_y] == make_pair(0,0)){
				x= new_x;
				y= new_y;
				dir = next+1;
				return;
			}
		}
		for (int i=0; i<4; i++){
			int next = priority[dir-1][i]-1;
			int new_x = dx[next] + x;
			int new_y = dy[next] + y;
			if (new_x >= 0 && new_x< N && new_y >= 0 && new_y < N && smell[new_x][new_y].first ==num ){
				x= new_x;
				y= new_y;
				dir = next+1;
				return;
			}
		}
	}
	void make_smell(){
		smell[x][y].first = num;
		smell[x][y].second = k;
	}
};
int main(){
	cin >>N >>M >>k;
	Shark *s[401];
	int shark_count = M;
	for (int i=1; i<=M; i++){
		s[i] = new Shark();
	}
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			smell[i][j] = make_pair(0,0);
			cin >>map[i][j];
			if (map[i][j] >0){
				s[map[i][j]]->x = i;
				s[map[i][j]]->y = j;
				s[map[i][j]]->num = map[i][j];
				s[map[i][j]]->make_smell();
			}
		}
	}

	for (int i=1; i<=M; i++){
		cin >> s[i]->dir;
	}

	for (int i=1; i<=M; i++)
		for (int j=0; j<4; j++)
			for (int k=0; k<4; k++)
				cin >> s[i]->priority[j][k];


	int time = 0;
	while (time <= 1000){
		
		for (int i=1; i<=M; i++){
			if (s[i] == NULL) continue;
			s[i]->move();
		}
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (smell[i][j].second>0){
					smell[i][j].second--;
					if (smell[i][j].second==0)
						smell[i][j] = make_pair(0,0);
				}
			}
		}
		for (int i=1; i<=M; i++){
			for (int j=i+1; j<=M; j++){
				if (s[i] == NULL || s[j] == NULL) continue;
				if (s[i]->x == s[j]->x && s[i]->y == s[j]->y){
					delete s[j];
					s[j] = NULL;
					shark_count--;
				}
			}
		}
		for (int i=1; i<=M; i++){
			if (s[i] == NULL) continue;
			s[i]->make_smell();
		}
		time++;
	
		if (shark_count==1) break;
	}
	if (time > 1000)
		cout <<"-1"<<"\n";
	else
		cout <<time<<"\n";
	return 0;
}