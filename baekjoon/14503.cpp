#include <iostream>
using namespace std;

bool map[50][50]={false,};
bool visited[50][50]={false};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	int r,c,d;
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin >> map[i][j];
			visited[i][j]= false;
		}
	}

	while(1){
		visited[r][c] = true;
		if (d == 0){
			if (c >0 && !map[r][c-1] && !visited[r][c-1]){
				c--;
				d =3;
			}
			else if ((r==0 || (r>0 && (map[r-1][c] || visited[r-1][c]))) && (r==N-1 || (r<N-1 && (map[r+1][c]|| visited[r+1][c]))) && (c==0 || (c>0 &&  (map[r][c-1]|| visited[r][c-1] ))) &&(c==M-1 || (c<M-1 &&  (map[r][c+1] || visited[r][c+1])))){
				if (r == N-1 || (r < N-1 && map[r+1][c]))
					break;
				else
					r++;
			}
			else 
				d =3;
			
		}

		else if (d== 1){
			if (r >0 && !map[r-1][c] && !visited[r-1][c]){
				r--;
				d =0;
			}
			else if ((r==0 || (r>0 && (map[r-1][c] || visited[r-1][c]))) && (r==N-1 || (r<N-1 && (map[r+1][c]|| visited[r+1][c]))) && (c==0 || (c>0 &&  (map[r][c-1]|| visited[r][c-1] ))) &&(c==M-1 || (c<M-1 &&  (map[r][c+1] || visited[r][c+1])))){
				if (c == 0 || (c >0 && map[r][c-1]))
					break;
				else
					c--;
			}
			else 
				d =0;
		}

		else if (d==2){
			if (c <M-1 && !map[r][c+1] && !visited[r][c+1]){
				c++;
				d =1;
			}
			else if ((r==0 || (r>0 && (map[r-1][c] || visited[r-1][c]))) && (r==N-1 || (r<N-1 && (map[r+1][c]|| visited[r+1][c]))) && (c==0 || (c>0 &&  (map[r][c-1]|| visited[r][c-1] ))) &&(c==M-1 || (c<M-1 &&  (map[r][c+1] || visited[r][c+1])))){
				if (r == 0 || (r > 0 && map[r-1][c]))
					break;
				else
					r--;
			}
			else
				d =1;
			
		}

		else if (d==3){
			if (r <N-1 && !map[r+1][c] && !visited[r+1][c]){
				r++;
				d =2;
			}
			else if ((r==0 || (r>0 && (map[r-1][c] || visited[r-1][c]))) && (r==N-1 || (r<N-1 && (map[r+1][c]|| visited[r+1][c]))) && (c==0 || (c>0 &&  (map[r][c-1]|| visited[r][c-1] ))) &&(c==M-1 || (c<M-1 &&  (map[r][c+1] || visited[r][c+1])))){
				if (c == M-1 || (c < M-1 && map[r][c+1]))
					break;
				else
					c++;
			}
			else 
				d =2;
		}

	}
	int count =0;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (visited[i][j])
				count++;
		}
	}

	
	cout <<count<<"\n";
}