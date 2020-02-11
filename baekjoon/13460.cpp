#include <cstdio>
#include <queue>
using namespace std;
char map[10][10];
int N,M;
pair<int,int> goal;

class ball{
	public:
	ball(pair<int,int> r, pair<int,int> b, int c){
		red= r;
		blue = b;
		count = c;
	}
	pair<int,int> red;
	pair<int,int> blue;
	int count;
};

pair<int,int> move(int dir, pair<int,int> b){
	int x =b.first;
	int y= b.second;
	//north
	if (dir ==0){
		while(y>0 && (map[y-1][x]=='.'|| map[y-1][x] =='O')){
			y--;
			if (map[y][x] =='O')
				break;
		}
	}
	//south
	if (dir ==1){
		while(y<N-1 && (map[y+1][x]=='.'|| map[y+1][x] =='O')){
			y++;
			if (map[y][x] =='O')
				break;
		}
	}
	//east
	if (dir ==2){
		while(x<M-1 && (map[y][x+1]=='.'|| map[y][x+1] =='O')){
			x++;
			if (map[y][x] =='O')
				break;
		}
	}
	//west
	if (dir ==3){
		while(x>0 && (map[y][x-1]=='.'|| map[y][x-1] =='O')){
			x--;
			if (map[y][x] =='O')
				break;
		}
	}
	return make_pair(x,y);
}	

int main(){
	char cc;
	scanf("%d %d",&N,&M);
	scanf("%c",&cc);
	int r_x,r_y;
	int b_x,b_y;
	int ans=-1;
	for (int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%c",&map[i][j]);
			if (map[i][j]=='R'){
				r_x=j,r_y=i;
				map[i][j]='.';
			}
			else if (map[i][j] =='B'){
				b_x=j, b_y=i;
				map[i][j]='.';
			}
			else if (map[i][j] =='O'){
				goal.first = j, goal.second=i;
			}
		}
		char buf;
		scanf("%c",&buf);
	}
	ball b(make_pair(r_x,r_y),make_pair(b_x,b_y),0);
	queue<ball> q;
	q.push(b);

	while(!q.empty()){
		ball t = q.front();
		q.pop();
		if (t.count >10)
			break;

		if (t.red == goal){
			if (t.blue == goal)
				continue;
			else{
				ans = t.count;
				break;
			}	
		}
		if (t.blue == goal)
			continue;


		if (t.red.first < t.blue.first){
			pair<int,int> r = move(3,t.red);
			if (map[r.second][r.first] == '.')
				map[r.second][r.first] ='R';
			pair<int,int> b = move(3,t.blue);
			if (map[r.second][r.first] == 'R')
				map[r.second][r.first] ='.';
			ball res(r,b,t.count+1);
			if (r != t.red || b != t.blue )
				q.push(res);

			pair<int,int> b2 = move(2,t.blue);
			if (map[b2.second][b2.first] == '.')				
				map[b2.second][b2.first] ='B';
			pair<int,int> r2 = move(2,t.red);
			if (map[b2.second][b2.first] == 'B')
				map[b2.second][b2.first] ='.';
			ball res2(r2,b2,t.count+1);
			if (r2 != t.red || b2 != t.blue )
				q.push(res2);
		}
		else{
			pair<int,int> b = move(3,t.blue);
			if (map[b.second][b.first] == '.')	
				map[b.second][b.first] ='B';
			pair<int,int> r = move(3,t.red);
			if (map[b.second][b.first] == 'B')	
				map[b.second][b.first] ='.';
			ball res(r,b,t.count+1);
			if (r != t.red || b != t.blue )
				q.push(res);

			pair<int,int> r2 = move(2,t.red);
			if (map[r2.second][r2.first] == '.')
				map[r2.second][r2.first] ='R';
			pair<int,int> b2 = move(2,t.blue);
			if (map[r2.second][r2.first] == 'R')
				map[r2.second][r2.first] ='.';
			ball res2(r2,b2,t.count+1);
			if (r2 != t.red || b2 != t.blue )
				q.push(res2);

		}
		if (t.red.second < t.blue.second){
			pair<int,int> b = move(1,t.blue);
			if (map[b.second][b.first] == '.')	
				map[b.second][b.first] ='B';
			pair<int,int> r = move(1,t.red);
			if (map[b.second][b.first] == 'B')	
				map[b.second][b.first] ='.';
			ball res(r,b,t.count+1);
			if (r != t.red || b != t.blue )
				q.push(res);

			pair<int,int> r2 = move(0,t.red);
			if (map[r2.second][r2.first] == '.')
				map[r2.second][r2.first] ='R';
			pair<int,int> b2 = move(0,t.blue);
			if (map[r2.second][r2.first] == 'R')
				map[r2.second][r2.first] ='.';
			ball res2(r2,b2,t.count+1);
			if (r2 != t.red || b2 != t.blue )
				q.push(res2);
			}
		else{
			
			pair<int,int> r = move(1,t.red);
			if (map[r.second][r.first] == '.')
				map[r.second][r.first] ='R';
			pair<int,int> b = move(1,t.blue);
			if (map[r.second][r.first] == 'R')
				map[r.second][r.first] ='.';
			ball res(r,b,t.count+1);
			if (r != t.red || b != t.blue )
				q.push(res);

			pair<int,int> b2 = move(0,t.blue);
			if (map[b2.second][b2.first] == '.')	
				map[b2.second][b2.first] ='B';
			pair<int,int> r2 = move(0,t.red);
			if (map[b2.second][b2.first] == 'B')	
				map[b2.second][b2.first] ='.';
			ball res2(r2,b2,t.count+1);
			if (r2 != t.red || b2 != t.blue )
				q.push(res2);
		}
	}

	printf("%d\n",ans);

}