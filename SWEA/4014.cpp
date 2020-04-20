#include<iostream>
#include <vector>
#include<cmath>
using namespace std;

int check_arr(vector<vector<int> > &arr, int X,int N){
	int count = 0;
	for (int i=0; i<2*N; i++){
		vector<int> check(N,false);
		for (int j=0; j<N-1; j++){
			if (abs(arr[i][j]-arr[i][j+1]) > 1) {
				count++;
				break;
			}
			else if (arr[i][j+1]-arr[i][j] == 1){
				bool flag= true;
				for (int c =j-1; c>j-X; c--){
					if (c <0 || arr[i][j] != arr[i][c] || check[c])
						flag = false;
					else
						check[c] = true;
				}
				if (!flag){
					count++;
					break;
				}
			}	
			else if (arr[i][j]-arr[i][j+1] == 1){
				bool flag = true;
				for (int c=j+1; c<j+1+X; c++){
					if (c >= N || arr[i][j+1] != arr[i][c] || check[c])
						flag = false;
					else
						check[c] = true;
				}
				if (!flag){
					count++;
					break;
				}
			}
		}
	}
	return 2*N- count;
}


int main(){
	int T;
	cin >>T;
	for (int t=1; t<=T; t++){
		int N, X;
		cin >>N>>X;
		vector<vector<int> > arr(2*N, vector<int>(N,0));
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				cin >>arr[i][j];
			}
		}
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				arr[i+N][j]= arr[j][i];
			}
		}


		cout << "#"<<t<<" " <<check_arr(arr,X,N)<<"\n";
	}
}