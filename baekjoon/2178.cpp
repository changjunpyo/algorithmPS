#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;
  const int dx[4] = {1,0,-1,0};
  const int dy[4] = {0,1,0,-1};
  const int MAX_COUNT = 987654321;
class maze{
	
  public:
	  maze(int N, int M){
	    for (int i=0; i<N; i++){
	      string s ;
  	      cin >> s;
	      for (int j=0; j<M; j++){
	      	arr[i][j] = s[j] -'0';
	      }
	    }
	    row = M;
	    col = N;
	  }
	  int find_shortest_path_length(){
	  	queue<pair<int,int>> q;
	  	q.push(make_pair(0,0));
	  	int count =1;
	  	while(!q.empty() ){
	  		count++;
	  		int q_size = q.size();
	  		for (int i=0; i<q_size; i++){
	  			auto pos = q.front();
	  			q.pop();
	  			for (int dir=0; dir<4; dir++){
	  				int n_x = pos.first + dx[dir];
	  				int n_y = pos.second + dy[dir];
	  				if (n_x == col-1 && n_y == row-1) return count;
	  				if (n_x >= 0 && n_x < col && n_y >=0 && n_y < row && arr[n_x][n_y]&&
	  					!visited[n_x][n_y]){
	  					visited[n_x][n_y] = true;
	  					q.push(make_pair(n_x, n_y));

	  				}
	  			}
	  		}
	  	}
	  	return -1;
	  }
  private:
	  int arr[100][100];
	  bool visited[100][100]={false,};
	  
	  int row;
	  int col;
	  

};

int main(){
  int N, M;

  cin >>N >>M;
  maze m = maze(N, M);
  cout << m.find_shortest_path_length()<<"\n"; 
  
  return 0;

  
}
