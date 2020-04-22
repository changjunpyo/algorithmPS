#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
bool map[20][20] ={0,};

int max_val(int k, int N, int M){
	int ans = 0;
	int sum = k*k + (k-1)*(k-1);
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			int num= 0;
			for (int x= i-k+1; x<=i+k-1; x++){
				if (x < 0 || x >= N) continue;
				for (int y = j-k+1; y<=j+k-1; y++){
					if (y <0 || y>=N || abs(i- x) + abs(j-y) >k-1) continue;
					if (map[x][y]) num++; 
				}
			}
			if (num*M - sum >= 0){
				ans = max(num, ans);
			}
		}
	}
	return ans;
}


int main(){
	int T;
	cin >>T;

	for (int t=1; t<=T; t++){
		
		int N, M;
		cin >>N >>M;
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				cin >> map[i][j];
			}
		}

		int ans = 1;
		for (int i=2; i<=N+1; i++){
			ans = max(max_val(i, N,M), ans);
		}

		cout << "#"<<t<<" " <<ans <<"\n";
	}
}