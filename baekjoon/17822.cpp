#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,M,T;
void round_circle(vector<vector<int> > &circle, int x, int d, int k){
	for (int i=x-1; i<N; i+=x){
		vector<int> v(circle[i].size(),0);
		for (int j=0; j<M; j++){
			if (d==0)
				v[(j+k)%M] = circle[i][j];
			else {
				int x = j-k+M;
				v[x%M] = circle[i][j];
			}
		}
		circle[i] = v;
	}
}
void check_circle(vector<vector<int> > &circle){
	vector<vector<bool> > check(N, vector<bool>(M,false));
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (circle[i][j] == 0) continue;
			if (i+1 != N &&circle[i][j] == circle[(i+1)%N][j])
				check[i][j] = check[(i+1)%N][j] = true;
			if (circle[i][j] == circle[i][(j+1)%M])
				check[i][j] = check[i][(j+1)%M] =true;
			int x = i-1;
			int y = j-1;
			if (y <0) y = M-1;
			if (circle[i][j] == circle[i][y])
				check[i][j] = check[i][y] =true;
			if (x >= 0 && circle[i][j] == circle[x][j])
				check[i][j] = check[x][j] =true;
		}
	}
	int count=0;
	int n = 0;
	int sum = 0;
	double avg;
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			if (circle[i][j] == 0) continue;
			if (check[i][j]){
				circle[i][j] =0;
				count++;
				continue;
			}
			sum += circle[i][j];
			n++;
		}
	}
	if (n==0) return;
	avg = sum/(double)n;
	if (count ==0){
		for (int i=0; i<N; i++){
			for (int j=0; j<M; j++){
				if (circle[i][j]==0) continue;
				if (abs(avg - circle[i][j]) < 0.0000001) continue;
				if (circle[i][j] > avg) circle[i][j] -=1;
				else circle[i][j]+=1;
			}
		}
	}
}

int total_sum(vector<vector<int> > &circle){
	int ret = 0;
	for (int i=0; i<N; i++){
			for (int j=0; j<M; j++){
				if (circle[i][j]==0) continue;
				ret+= circle[i][j];
			}
		}
	return ret;
}

int main(){
	
	cin >>N >>M>>T;
	vector<vector<int> > circle(N, vector<int>(M));
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			cin >>circle[i][j];
		}
	}
	for (int i=0; i<T; i++){
		int x,d,k;
		cin >>x>>d>>k;
		round_circle(circle, x,d,k);
		
		check_circle(circle);
		
	}
	cout <<total_sum(circle)<<"\n";
	return 0;

}