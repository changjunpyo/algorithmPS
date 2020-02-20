#include <bits/stdc++.h>
using namespace std;
#define SWAP(a,b) {int t; t=a; a=b; b=t;}
int main(){
	int N;
	cin >>N;
	vector<int> arr(N+1,-2);
	for (int i=1; i<=N; i++)
		cin >>arr[i];

	//selection sort based

	for (int i=1; i<=N; i++){
		int x = 987654321;
		int x_idx=i;
		for (int j=i; j<=N; j++){
			if (arr[j] <x && arr[j] != arr[i-1]+1){
				x = arr[j];
				x_idx = j;
			}
		}
		SWAP(arr[i],arr[x_idx]);
		for (int j=i; j>1; j--){
			if (arr[j] == arr[j-1]+1){
				SWAP(arr[j], arr[j-1]);
			}
		}
	}
	for (int i=1; i<=N; i++){
		cout <<arr[i]<<" ";
	}
	cout <<"\n";
}

