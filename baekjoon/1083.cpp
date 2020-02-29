#include <iostream>
#include <algorithm>
using namespace std;
	int arr[50];
void bubble(int count, int N){

	for (int i=0; i<N; i++){
		if (count==0) break;
		int mx = 0;
		int idx = -1;
		for(int j=i; j<N && j<=count+i; j++){
			if (mx <arr[j]){
				mx = arr[j];
				idx = j;
				}
		}

		for (int j=idx; j>0; j--){
			if (count ==0) break;
			if (arr[j] >arr[j-1]){
				count--;
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

bool cmp(int a, int b){
	return a > b;
}
int main(){
	int N;
	cin >>N; 
	for (int i=0; i<N; i++ )
		cin >>arr[i];
	int s;
	cin >>s;
	bubble(s,N);
	for (int i=0; i<N; i++)
		cout <<arr[i]<<" ";
	cout <<"\n";
}